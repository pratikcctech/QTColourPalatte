#pragma once

#include <QtWidgets/QMainWindow>
#include "Visualizer.h"
#include "OpenGlWindow.h"
#include "Point.h"

class OpenGLWindow;

class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();
    void onSpinBoxValueChanged(double value);
    void calculateCollision();
    void bezierClicked();
    void hermiteClicked();
    void bSplineClicked();
    void colourSelect();
    
private:
    void setupUi();
    

private:
    /*QMenuBar* mMenuBar;
    QToolBar* mMainToolBar;
    QWidget* mCentralWidget;
    QStatusBar* mStatusBar;*/
    OpenGLWindow* mRenderer;
    /*QDoubleSpinBox* mDoubleSpinBox;
    double mSpinBoxValue;
    QLabel* mValueLabel;*/

    QWidget* centralWidget;
    QDoubleSpinBox* doubleSpinBox;
    QLabel* label;
    QDoubleSpinBox* doubleSpinBox_2;
    QLabel* label_2;
    QLabel* label_3;
    QDoubleSpinBox* doubleSpinBox_3;
    QLabel* label_4;
    QDoubleSpinBox* doubleSpinBox_4;
    QDoubleSpinBox* doubleSpinBox_5;
    QDoubleSpinBox* doubleSpinBox_6;
    QDoubleSpinBox* doubleSpinBox_7;
    QDoubleSpinBox* doubleSpinBox_8;
    QDoubleSpinBox* doubleSpinBox_9;
    QDoubleSpinBox* doubleSpinBox_10;
    QDoubleSpinBox* doubleSpinBox_11;
    QDoubleSpinBox* doubleSpinBox_12;
    QDoubleSpinBox* doubleSpinBox_13;
    QDoubleSpinBox* doubleSpinBox_14;
    QDoubleSpinBox* doubleSpinBox_15;
    QDoubleSpinBox* doubleSpinBox_16;
    QDoubleSpinBox* doubleSpinBox_17;
    QDoubleSpinBox* doubleSpinBox_18;
    QDoubleSpinBox* doubleSpinBox_19;
    QDoubleSpinBox* doubleSpinBox_20;
    QDoubleSpinBox* doubleSpinBox_21;
    QDoubleSpinBox* doubleSpinBox_22;
    QDoubleSpinBox* doubleSpinBox_23;
    QDoubleSpinBox* doubleSpinBox_24;
    QDoubleSpinBox* doubleSpinBox_25;
    QDoubleSpinBox* doubleSpinBox_26;
    QDoubleSpinBox* doubleSpinBox_27;
    QDoubleSpinBox* doubleSpinBox_28;
    QDoubleSpinBox* doubleSpinBox_29;
    QDoubleSpinBox* doubleSpinBox_30;
    QDoubleSpinBox* doubleSpinBox_31;
    QDoubleSpinBox* doubleSpinBox_32;
    

    QLabel* label_5;
    QLabel* label_6;
    QLabel* label_7;
    QLabel* label_8;
    QLabel* label_9;
    QLabel* label_10;
    QLabel* label_11;
    QLabel* label_12;
    QLabel* label_13;
    QLabel* label_14; 
    QLabel* label_15;
    QLabel* label_16;
    QLabel* label_17;
    QLabel* label_18;
    QLabel* label_19;
    QLabel* label_20;
    QLabel* label_21;
    QLabel* label_22;
    QLabel* label_23;
    QLabel* label_24;
    QLabel* label_25;
    QLabel* label_26;
    QLabel* label_27;
    QLabel* label_28;
    QLabel* label_29;
    QLabel* label_30;
    QLabel* label_31;
    QLabel* label_32;

    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QPushButton* pushButton_3;
    QPushButton* pushButton_4;
    QPushButton* pushButton_5;
    QOpenGLWidget* openGLWidget;
    QToolBar* mainToolBar;
    QStatusBar* statusBar;
    QGridLayout* gridLayout;
    QWidget* gridLayoutWidget;
    QTabWidget* tabWidget;
    QWidget* tab_3;
    QWidget* tab_2;
    QWidget* tab_4;
    QWidget* tab;
    QWidget* tab_5;
    QSpacerItem* horizontalSpacer_2;
    QSpacerItem* horizontalSpacer;
    QSpacerItem* horizontalSpacer_3;

public:
    std::vector<float> mVerticess;
    std::vector<float> mColorss;
    std::vector<Point> mPoints;
    QVector<GLfloat>   mVertices;
    QVector<GLfloat>   mColors;

};