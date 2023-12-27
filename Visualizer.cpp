    #include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"
#include "Bezier.h"
#include "Hermite.h"
#include "BSpline.h"

Visualizer::Visualizer(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
    connect(mRenderer, SIGNAL(dataUpdate()), mRenderer, SLOT(update()));

    //adding the command to call the function when pressed the push button of collision detection tab
    connect(pushButton, &QPushButton::clicked, this, &Visualizer::calculateCollision);
    //adding the command to call the function when pressed the push button of Bezier tab
    connect(pushButton_2, &QPushButton::clicked, this, &Visualizer::bezierClicked);
    //adding the command to call the function when pressed the push button of hermite  tab
    connect(pushButton_3, &QPushButton::clicked, this, &Visualizer::hermiteClicked);
    //adding the command to call the function when pressed the push button of bSpline  tab
    connect(pushButton_4, &QPushButton::clicked, this, &Visualizer::bSplineClicked);
    connect(pushButton_5, &QPushButton::clicked, this, &Visualizer::colourSelect);

}

Visualizer::~Visualizer()
{}


//ui of the whole Project of the visualizer
void Visualizer::setupUi() {
    
    
        resize(1071, 616);
        centralWidget = new QWidget(this);
        centralWidget->setObjectName("centralWidget");
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(50, 40, 941, 511));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName("tabWidget");
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
       
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 190, 101, 24));
        pushButton->setText("FIND COLLISION");
        label = new QLabel(tab_3);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 43, 21));
        label->setText("Enter x1");
        label_5 = new QLabel(tab_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 10, 49, 21));
        label_5->setText("Enter x2");
        doubleSpinBox = new QDoubleSpinBox(tab_3);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(70, 10, 50, 21));
        doubleSpinBox->setMinimum(-100.000000000000000);
        doubleSpinBox->setMaximum(100.000000000000000);
        doubleSpinBox_5 = new QDoubleSpinBox(tab_3);
        doubleSpinBox_5->setObjectName("doubleSpinBox_5");
        doubleSpinBox_5->setGeometry(QRect(230, 10, 50, 21));
        doubleSpinBox_5->setMinimum(-100.000000000000000);
        doubleSpinBox_5->setMaximum(100.000000000000000);
        label_2 = new QLabel(tab_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 44, 21));
        label_2->setText("enter y1");
        label_6 = new QLabel(tab_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(170, 50, 49, 21));
        label_6->setText("enter y2");
        doubleSpinBox_2 = new QDoubleSpinBox(tab_3);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setGeometry(QRect(70, 50, 50, 21));
        doubleSpinBox_2->setMinimum(-100.000000000000000);
        doubleSpinBox_2->setMaximum(100.000000000000000);
        doubleSpinBox_6 = new QDoubleSpinBox(tab_3);
        doubleSpinBox_6->setObjectName("doubleSpinBox_6");
        doubleSpinBox_6->setGeometry(QRect(230, 50, 50, 21));
        doubleSpinBox_6->setMinimum(-100.000000000000000);
        doubleSpinBox_6->setMaximum(100.000000000000000);
        label_3 = new QLabel(tab_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 49, 21));
        label_3->setText("enter vx1");
        label_7 = new QLabel(tab_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(170, 90, 49, 21));
        label_7->setText("enter vx2");
        doubleSpinBox_3 = new QDoubleSpinBox(tab_3);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");
        doubleSpinBox_3->setGeometry(QRect(70, 90, 50, 21));
        doubleSpinBox_3->setMinimum(-100.000000000000000);
        doubleSpinBox_3->setMaximum(100.000000000000000);
        doubleSpinBox_7 = new QDoubleSpinBox(tab_3);
        doubleSpinBox_7->setObjectName("doubleSpinBox_7");
        doubleSpinBox_7->setGeometry(QRect(230, 90, 50, 20));
        doubleSpinBox_7->setMinimum(-100.000000000000000);
        doubleSpinBox_7->setMaximum(100.000000000000000);
        label_4 = new QLabel(tab_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 130, 49, 21));
        label_4->setText("enter vy1");
        doubleSpinBox_4 = new QDoubleSpinBox(tab_3);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");
        doubleSpinBox_4->setGeometry(QRect(70, 130, 50, 21));
        doubleSpinBox_4->setMinimum(-100.000000000000000);
        doubleSpinBox_4->setMaximum(100.000000000000000);
        label_8 = new QLabel(tab_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(170, 130, 49, 21));
        label_8->setText("enter vy2");
        doubleSpinBox_8 = new QDoubleSpinBox(tab_3);
        doubleSpinBox_8->setObjectName("doubleSpinBox_8");
        doubleSpinBox_8->setGeometry(QRect(230, 130, 50, 21));
        doubleSpinBox_8->setMinimum(-100.000000000000000);
        doubleSpinBox_8->setMaximum(100.000000000000000);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        mRenderer = new OpenGLWindow(QColor(0, 0, 0),centralWidget);
        mRenderer->setObjectName("openGLWidget");

        gridLayout->addWidget(mRenderer, 1, 0, 1, 4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        setCentralWidget(centralWidget);
        statusBar = new QStatusBar(this);
        statusBar->setObjectName("statusBar");
        setStatusBar(statusBar);

        //setting the text to the tabs for specific identification
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("QtWidgetsApplication1Class", "CollisionDetection", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("QtWidgetsApplication1Class", "Bezier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("QtWidgetsApplication1Class", "Hermite ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("QtWidgetsApplication1Class", "B-Spline", nullptr));

        label_9 = new QLabel(tab_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 40, 49, 16));
        doubleSpinBox_9 = new QDoubleSpinBox(tab_4);
        doubleSpinBox_9->setObjectName("doubleSpinBox_9");
        doubleSpinBox_9->setGeometry(QRect(80, 40, 62, 22));
        doubleSpinBox_9->setMinimum(-100.000000000000000);
        doubleSpinBox_9->setMaximum(100.000000000000000);
        label_10 = new QLabel(tab_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(160, 40, 49, 16));
        doubleSpinBox_10 = new QDoubleSpinBox(tab_4);
        doubleSpinBox_10->setObjectName("doubleSpinBox_10");
        doubleSpinBox_10->setGeometry(QRect(230, 40, 62, 22));
        doubleSpinBox_10->setMinimum(-100.000000000000000);
        doubleSpinBox_10->setMaximum(100.000000000000000);
        label_11 = new QLabel(tab_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 100, 49, 16));
        doubleSpinBox_11 = new QDoubleSpinBox(tab_4);
        doubleSpinBox_11->setObjectName("doubleSpinBox_11");
        doubleSpinBox_11->setGeometry(QRect(80, 90, 62, 22));
        doubleSpinBox_11->setMinimum(-100.000000000000000);
        doubleSpinBox_11->setMaximum(100.000000000000000);
        label_12 = new QLabel(tab_4);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(160, 100, 49, 16));
        doubleSpinBox_12 = new QDoubleSpinBox(tab_4);
        doubleSpinBox_12->setObjectName("doubleSpinBox_12");
        doubleSpinBox_12->setGeometry(QRect(230, 90, 62, 22));
        doubleSpinBox_12->setMinimum(-100.000000000000000);
        doubleSpinBox_12->setMaximum(100.000000000000000);
        label_13 = new QLabel(tab_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 150, 49, 16));
        doubleSpinBox_13 = new QDoubleSpinBox(tab_4);
        doubleSpinBox_13->setObjectName("doubleSpinBox_13");
        doubleSpinBox_13->setGeometry(QRect(80, 150, 62, 22));
        doubleSpinBox_13->setMinimum(-100.000000000000000);
        doubleSpinBox_13->setMaximum(100.000000000000000);
        label_14 = new QLabel(tab_4);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(160, 150, 49, 16));
        doubleSpinBox_14 = new QDoubleSpinBox(tab_4);
        doubleSpinBox_14->setObjectName("doubleSpinBox_14");
        doubleSpinBox_14->setGeometry(QRect(230, 150, 62, 22));
        doubleSpinBox_14->setMinimum(-100.000000000000000);
        doubleSpinBox_14->setMaximum(100.000000000000000);
        label_15 = new QLabel(tab_4);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 200, 49, 16));
        doubleSpinBox_15 = new QDoubleSpinBox(tab_4);
        doubleSpinBox_15->setObjectName("doubleSpinBox_15");
        doubleSpinBox_15->setGeometry(QRect(80, 200, 62, 22));
        doubleSpinBox_15->setMinimum(-100.000000000000000);
        doubleSpinBox_15->setMaximum(100.000000000000000);
        label_16 = new QLabel(tab_4);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(160, 200, 49, 16));
        doubleSpinBox_16 = new QDoubleSpinBox(tab_4);
        doubleSpinBox_16->setObjectName("doubleSpinBox_16");
        doubleSpinBox_16->setGeometry(QRect(230, 200, 62, 22));
        doubleSpinBox_16->setMinimum(-100.000000000000000);
        doubleSpinBox_16->setMaximum(100.000000000000000);
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(110, 250, 121, 41));

        //
        label_17 = new QLabel(tab);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 40, 49, 16));
        doubleSpinBox_17 = new QDoubleSpinBox(tab);
        doubleSpinBox_17->setObjectName("doubleSpinBox_17");
        doubleSpinBox_17->setGeometry(QRect(100, 40, 62, 22));
        doubleSpinBox_17->setMinimum(-100.000000000000000);
        doubleSpinBox_17->setMaximum(100.000000000000000);
        label_18 = new QLabel(tab);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(190, 40, 49, 16));
        doubleSpinBox_18 = new QDoubleSpinBox(tab);
        doubleSpinBox_18->setObjectName("doubleSpinBox_18");
        doubleSpinBox_18->setGeometry(QRect(270, 30, 62, 22));
        doubleSpinBox_18->setMinimum(-100.000000000000000);
        doubleSpinBox_18->setMaximum(100.000000000000000);
        label_19 = new QLabel(tab);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 90, 49, 16));
        doubleSpinBox_19 = new QDoubleSpinBox(tab);
        doubleSpinBox_19->setObjectName("doubleSpinBox_19");
        doubleSpinBox_19->setGeometry(QRect(100, 90, 62, 22));
        doubleSpinBox_19->setMinimum(-100.000000000000000);
        doubleSpinBox_19->setMaximum(100.000000000000000);
        label_20 = new QLabel(tab);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(190, 90, 49, 16));
        doubleSpinBox_20 = new QDoubleSpinBox(tab);
        doubleSpinBox_20->setObjectName("doubleSpinBox_20");
        doubleSpinBox_20->setGeometry(QRect(270, 80, 62, 22));
        doubleSpinBox_20->setMinimum(-100.000000000000000);
        doubleSpinBox_20->setMaximum(100.000000000000000);
        label_21 = new QLabel(tab);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(20, 140, 49, 16));
        doubleSpinBox_21 = new QDoubleSpinBox(tab);
        doubleSpinBox_21->setObjectName("doubleSpinBox_21");
        doubleSpinBox_21->setGeometry(QRect(100, 140, 62, 22));
        doubleSpinBox_21->setMinimum(-100.000000000000000);
        doubleSpinBox_21->setMaximum(100.000000000000000);
        label_22 = new QLabel(tab);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(190, 140, 49, 16));
        doubleSpinBox_22 = new QDoubleSpinBox(tab);
        doubleSpinBox_22->setObjectName("doubleSpinBox_22");
        doubleSpinBox_22->setGeometry(QRect(270, 130, 62, 22));
        doubleSpinBox_22->setMinimum(-100.000000000000000);
        doubleSpinBox_22->setMaximum(100.000000000000000);
        label_23 = new QLabel(tab);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(20, 190, 49, 16));
        doubleSpinBox_23 = new QDoubleSpinBox(tab);
        doubleSpinBox_23->setObjectName("doubleSpinBox_23");
        doubleSpinBox_23->setGeometry(QRect(100, 180, 62, 22));
        doubleSpinBox_23->setMinimum(-100.000000000000000);
        doubleSpinBox_23->setMaximum(100.000000000000000);
        label_24 = new QLabel(tab);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(190, 190, 49, 16));
        doubleSpinBox_24 = new QDoubleSpinBox(tab);
        doubleSpinBox_24->setObjectName("doubleSpinBox_24");
        doubleSpinBox_24->setGeometry(QRect(270, 180, 62, 22));
        doubleSpinBox_24->setMinimum(-100.000000000000000);
        doubleSpinBox_24->setMaximum(100.000000000000000);
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(130, 260, 121, 41));
        pushButton_3->setText("Calculate Hermite");
        label_17->setText("Enter X1");
        label_18->setText("Enter Y1");
        label_19->setText("Enter X2");
        label_20->setText("Enter Y2");
        label_21->setText("Enter X3");
        label_22->setText("Enter Y3");
        label_23->setText("Enter X4");
        label_24->setText("Enter X5");

        //

        label_25 = new QLabel(tab_2);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(30, 30, 49, 16));
        doubleSpinBox_25 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_25->setObjectName("doubleSpinBox_25");
        doubleSpinBox_25->setGeometry(QRect(100, 30, 62, 22));
        label_26 = new QLabel(tab_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(190, 30, 49, 16));
        doubleSpinBox_26 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_26->setObjectName("doubleSpinBox_26");
        doubleSpinBox_26->setGeometry(QRect(260, 30, 62, 22));
        label_27 = new QLabel(tab_2);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(30, 90, 49, 16));
        doubleSpinBox_27 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_27->setObjectName("doubleSpinBox_27");
        doubleSpinBox_27->setGeometry(QRect(100, 90, 62, 22));
        label_28 = new QLabel(tab_2);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(190, 90, 49, 16));
        doubleSpinBox_28 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_28->setObjectName("doubleSpinBox_28");
        doubleSpinBox_28->setGeometry(QRect(260, 90, 62, 22));
        label_29 = new QLabel(tab_2);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(30, 140, 49, 16));
        doubleSpinBox_29 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_29->setObjectName("doubleSpinBox_29");
        doubleSpinBox_29->setGeometry(QRect(100, 140, 62, 22));
        label_30 = new QLabel(tab_2);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(190, 140, 49, 16));
        doubleSpinBox_30 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_30->setObjectName("doubleSpinBox_30");
        doubleSpinBox_30->setGeometry(QRect(260, 140, 62, 22));
        label_31 = new QLabel(tab_2);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(30, 190, 49, 16));
        doubleSpinBox_31 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_31->setObjectName("doubleSpinBox_31");
        doubleSpinBox_31->setGeometry(QRect(100, 190, 62, 22));
        label_32 = new QLabel(tab_2);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(190, 190, 49, 16));
        doubleSpinBox_32 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_32->setObjectName("doubleSpinBox_32");
        doubleSpinBox_32->setGeometry(QRect(260, 190, 62, 22));
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(130, 250, 121, 41));
        pushButton_4->setText("Calculate B-Spline");
        label_25->setText("Enter X1");
        label_26->setText("Enter Y1");
        label_27->setText("Enter X2");
        label_28->setText("Enter Y2");
        label_29->setText("Enter X3");
        label_30->setText("Enter Y3");
        label_31->setText("Enter X4");
        label_32->setText("Enter Y4");
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        pushButton_5 = new QPushButton(tab_5);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(110, 40, 151, 41));
        tabWidget->addTab(tab_5, QString());
        pushButton_5->setText("color palette");
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("QtWidgetsApplication1Class", "color palette", nullptr));



        label_9->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Enter X1", nullptr));
        label_10->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Enter Y1", nullptr));
        label_11->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Enter X2", nullptr));
        label_12->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Enter Y2", nullptr));
        label_13->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Enter X3", nullptr));
        label_14->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Enter Y3", nullptr));
        label_15->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Enter X4", nullptr));
        label_16->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Enter Y4", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Calculate Bezier", nullptr));
    
}



//the function defination of the collision detection algorithm

void Visualizer::calculateCollision()
{

    //storing the values of the user input into variable for processing
    double x1 = doubleSpinBox->value();
    double y1 = doubleSpinBox_2->value();
    double x2 = doubleSpinBox_5->value();
    double y2 = doubleSpinBox_6->value();
    //storing the velcities of the user inout into variable
    double vx1 = doubleSpinBox_3->value();
    double vy1 = doubleSpinBox_4->value();
    double vx2 = doubleSpinBox_7->value();
    double vy2 = doubleSpinBox_8->value();

    //creating the collisiondetection class object to perform the operation
    CollisionDetection c1;
    c1.setPointFirst(Point(x1, y1));
    c1.setPointSecond(Point(x2, y2));
    c1.setVelocityFirst(Velocity(vx1, vy1));
    c1.setVelocitySecond(Velocity(vx2, vy2));
    //calling the collision detecion function to get the collision point and stored into the member function
    c1.findCollisionPoint();


    //assigning the sequence in such a way that the collision point should be matched
    mPoints.push_back( Point(c1.PointFirst().X(), c1.PointFirst().Y()));
    mPoints.push_back(Point(c1.CollisionPoint().X(), c1.CollisionPoint().Y()));
    mPoints.push_back(Point(c1.PointSecond().X(), c1.PointSecond().Y()));

    //seeting the vertices of the points in order to provide to openGL window
    for (int i = 0; i < mPoints.size() - 1; i++)
    {
        mVertices << mPoints[i].X() << mPoints[i].Y();
        mVertices << mPoints[i + 1].X() << mPoints[i + 1].Y();
        mColors << 1.0f << 1.0f << 1.0f;
        mColors << 1.0f << 1.0f << 1.0f;
    }

    //passing the data to openGl window
    mRenderer->updateData(mVertices, mColors);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
    mPoints.clear();
   
    
}

//the function defination of the bezier curve algorithm
void Visualizer::bezierClicked()
{

    //storing the values of the user input into variable for processing
    double x1 = doubleSpinBox_9->value();
    double y1 = doubleSpinBox_10->value();
 
    double x2 = doubleSpinBox_11->value();
    double y2 = doubleSpinBox_12->value();
 
    double x3 = doubleSpinBox_13->value();
    double y3 = doubleSpinBox_14->value();
 
    double x4 = doubleSpinBox_15->value();
    double y4 = doubleSpinBox_16->value();
 
    //creating the object of point wrt values taken from user
    Point p0 = Point(x1, y1);
    Point p1 = Point(x2, y2);
    Point p2 = Point(x3, y3);
    Point p3 = Point(x4, y4);


    //creating the Bezier class object
    Bezier bezier(p0, p1, p2, p3);
    //calling the draw curve function in bezier class to create curve
    bezier.drawCurve(p0, p1, p2, p3, mVerticess, mColorss);


    //seting the vertices of the points in order to provide to openGL window
    mVertices << x1 << y1;
    mColors << 0.0f << 1.0f << 0.0f;

    for (int i = 0; i < mVerticess.size(); i += 2)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1] ;
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }

    mVertices << x4 << y4  ;
    mColors << 0.0f << 1.0f << 0.0f;

    //passing the data vector to opengl window
    mRenderer->updateData(mVertices, mColors);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
}

//the function defination of the hermite curve algorithm
void Visualizer::hermiteClicked()
{

    //storing the values of the user input into variable for processing
    double x0Coordinate = doubleSpinBox_17->value();
    double y0Coordinate = doubleSpinBox_18->value();
    

    double x1Coordinate = doubleSpinBox_19->value();
    double y1Coordinate = doubleSpinBox_20->value();
    

    double x2Coordinate = doubleSpinBox_21->value();
    double y2Coordinate = doubleSpinBox_22->value();
    

    double x3Coordinate = doubleSpinBox_23->value();
    double y3Coordinate = doubleSpinBox_24->value();
    
    //creating the object of point wrt values taken from user
    Point p0 = Point(x0Coordinate, y0Coordinate );
    Point p1 = Point(x1Coordinate, y1Coordinate);
    Point p2 = Point(x2Coordinate, y2Coordinate );
    Point p3 = Point(x3Coordinate, y3Coordinate );


    //creating the hermite class object
    Hermite hermite(p0, p1, p2, p3);
    //calling the draw curve function to creating the curve
    hermite.drawCurve(p0, p1, p2, p3, mVerticess, mColorss);


    //seting the vertices of the points in order to provide to openGL window
    mVertices << x0Coordinate << y0Coordinate;
    mColors << 0.0f << 1.0f << 0.0f;

    for (int i = 0; i < mVerticess.size(); i += 2)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1] ;
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }

    mVertices << x3Coordinate << y3Coordinate ;
    mColors << 0.0f << 1.0f << 0.0f;

    //passing the updated data to openGlwindow to render
    mRenderer->updateData(mVertices, mColors);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
}

//the function defination of the bSpline curve algorithm
void Visualizer::bSplineClicked()
{

    //storing the values of the user input into variable for processing
    double x0Coordinate = doubleSpinBox_25->value();
    double y0Coordinate = doubleSpinBox_26->value();


    double x1Coordinate = doubleSpinBox_27->value();
    double y1Coordinate = doubleSpinBox_28->value();


    double x2Coordinate = doubleSpinBox_29->value();
    double y2Coordinate = doubleSpinBox_30->value();


    double x3Coordinate = doubleSpinBox_31->value();
    double y3Coordinate = doubleSpinBox_32->value();
    
    //creating the object of point wrt values taken from user
    Point p0 = Point(x0Coordinate, y0Coordinate);
    Point p1 = Point(x1Coordinate, y1Coordinate);
    Point p2 = Point(x2Coordinate, y2Coordinate);
    Point p3 = Point(x3Coordinate, y3Coordinate);

    mPoints.push_back(p0);
    mPoints.push_back(p1);
    mPoints.push_back(p2);
    mPoints.push_back(p3);

    //creating the BSpline class object
    BSpline bs(3);
    //calling curve function to create the spline curve
    std::vector<Point> bsplinePoints = bs.evaluate(mPoints, 100);

    //storing the vertices to pass the openGLwindow
    for (int i = 0; i < bsplinePoints.size()-1; i++)
    {
        mVertices << bsplinePoints[i].X() << bsplinePoints[i].Y();
        mVertices << bsplinePoints[i+1].X() << bsplinePoints[i+1].Y();
        mColors << 0.0f << 1.0f << 1.0f;
        mColors << 0.0f << 1.0f << 1.0f;
    }

    //passing the updated data to openGlwindow to render
    mRenderer->updateData(mVertices, mColors);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
    mPoints.clear();

}

void Visualizer:: colourSelect()
{
    mRenderer->selectCurveColor();
}