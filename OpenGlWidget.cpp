#include "stdafx.h"
#include "OpenGLWindow.h"

#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include"CollisionDetection.h"

OpenGLWindow::OpenGLWindow(const QColor& background, QWidget* parent) :
    mBackground(background)
{
    setParent(parent);
    setMinimumSize(500, 250);
    const QStringList list = { "vertexShader.glsl" , "fragmentShader.glsl" };
    mShaderWatcher = new QFileSystemWatcher(list, this);

    connect(mShaderWatcher, &QFileSystemWatcher::fileChanged, this, &OpenGLWindow::shaderWatcher);
}
OpenGLWindow::~OpenGLWindow()
{
    reset();
}

void OpenGLWindow::reset()
{
    // And now release all OpenGL resources.
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();

    // We are done with the current QOpenGLContext, forget it. If there is a
    // subsequent initialize(), that will then connect to the new context.
    QObject::disconnect(mContextWatchConnection);
}

void OpenGLWindow::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);
    
    mProgram->setUniformValue(m_matrixUniform, matrix);
    mProgram->setUniformValue("r", r);
    mProgram->setUniformValue("g", g);
    mProgram->setUniformValue("b", b);

    //the vertices data contains all information of the Points which have to print on the openGl window
    GLfloat* verticesData = verticesOfOrignalLine.data();
    GLfloat* colorsData = colorOfOrignalLine.data();
    
    
    
        glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, verticesData);
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

        glEnableVertexAttribArray(m_posAttr);
        glEnableVertexAttribArray(m_colAttr);

        glDrawArrays(GL_LINES, 0, verticesOfOrignalLine.size() / 2);
    
    
    

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);


}

void OpenGLWindow::initializeGL()
{
    /*static const char* vertexShaderSource =
        "attribute highp vec4 posAttr;\n"
        "attribute lowp vec4 colAttr;\n"
        "varying lowp vec4 col;\n"
        "uniform highp mat4 matrix;\n"
        "void main() {\n"
        "   col = colAttr;\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";

    static const char* fragmentShaderSource =
        "varying lowp vec4 col;\n"
        "void main() {\n"
        "   gl_FragColor = col;\n"
        "}\n";*/

        QString vertexShaderSource = readShader("vertexShader.glsl");
        QString fragmentShaderSource = readShader("fragmentShader.glsl");

    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();

    if (m_posAttr == -1 || m_colAttr == -1 || m_matrixUniform == -1)
    {
        qDebug() << "Shader attribute or uniform location error.";
        // Handle the error appropriately, e.g., return or throw an exception
    }
    m_posAttr = mProgram->attributeLocation("posAttr");
    m_colAttr = mProgram->attributeLocation("colAttr");
    m_matrixUniform = mProgram->uniformLocation("matrix");

}
void OpenGLWindow::shaderWatcher()
{
    QString vertexShaderSource = readShader("vertexShader.glsl");
    QString fragmentShaderSource = readShader("fragmentShader.glsl");

    mProgram->release();
    mProgram->removeAllShaders();
    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
}
QString OpenGLWindow::readShader(QString filePath) {
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "Invalid file";

    QTextStream stream(&file);
    QString line = stream.readLine();

    while (!stream.atEnd()) {
        line.append(stream.readLine());
    }
    file.close();
    return line;
}
void OpenGLWindow::selectCurveColor()
{
    QColorDialog colorDialog(this);
    QColor selectedColor = colorDialog.getColor();

    if (selectedColor.isValid()) {
        // Set the selected color to the curves or store it for later use
        r = selectedColor.redF();
        g = selectedColor.greenF();
        b = selectedColor.blueF();
        emit dataUpdate();  // Trigger an update to redraw the curves with the new color
    }
}



//updating the values which are updated by the algorithms
void OpenGLWindow::updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors)
{
    verticesOfOrignalLine = vertices;
    //colorOfOrignalLine = colors;
    for (int j = 0; j < vertices.size(); j++) {
        
        float currentR = r;
        float currentG = g;
        float currentB = b;

        colorOfOrignalLine.push_back(currentR);
        colorOfOrignalLine.push_back(currentG);
        colorOfOrignalLine.push_back(currentB);

        colorOfOrignalLine.push_back(currentR);
        colorOfOrignalLine.push_back(currentG);
        colorOfOrignalLine.push_back(currentB);
    }
    
    mVertices.clear();
    mNormals.clear();
    emit dataUpdate();  // Schedule a repaint
}