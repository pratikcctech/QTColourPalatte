#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include "Point.h"
#include"CollisionDetection.h"

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;

class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
signals:
    void dataUpdate();
public:
    OpenGLWindow(const QColor& background, QWidget* parent);
    ~OpenGLWindow();
    
    void createcollison(double x1, double y1, double x2, double y2, double vx1, double vy1, double vx2, double vy2);
    void setVectorOfLines(QVector<GLfloat>& vectorOfLines);
    void setColorOfLines(QVector<GLfloat>& colorOfLines);
    void updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors);
    void selectCurveColor();

protected:
    void paintGL() override;
    void initializeGL() override;

private:
    void quad(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4);
    void extrude(qreal x1, qreal y1, qreal x2, qreal y2);
    void reset();

private slots:
    void shaderWatcher();

private:
    bool mAnimating = false;
    QOpenGLContext* mContext = nullptr;
    QOpenGLPaintDevice* mDevice = nullptr;

    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;

    QList<Point> mVertices;
    QList<Point> mColors;
    QList<QVector3D> mNormals;
    QOpenGLBuffer mVbo;
    int mFlag=0;
    int mVertexAttr;
    int mNormalAttr;
    int mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;

    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;
    Point* verticesData;
    Point* colorsData;

    std::vector<float> vertices;
    std::vector<float> colors;
    float r=1;
    float g=1;
    float b=1;
public:
    CollisionDetection c1;
    QVector<GLfloat> verticesOfOrignalLine;
    QVector<GLfloat> colorOfOrignalLine;
    QFileSystemWatcher* mShaderWatcher;
    QString readShader(QString filePath);
};
