#include "game.h"

Game::Game()
{
    //std::string release = "outRelease";
    QFile *file = new QFile("123123.txt");
    if (file->open(QIODevice::WriteOnly))
    {
        stream = new QTextStream(file);
    }

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, widthOfFrame, heightOfFrame);
    landscape = new Landscape();
    tank1 = new Tank(100, 100);
    tank2 = new Tank(500, 200);
    scene->addItem(landscape);
    scene->addItem(tank1);
    scene->addItem(tank2);
    //landscape->setFlags(QGraphicsItem::ItemIsMovable);
    updater = new Updater();

    connect(updater, SIGNAL(doUpdate()), this, SLOT(update()));
    //updater->execute();

}

Game::~Game()
{
    //outPress->close();
    //outRelease->close();

    //delete outPress;
    //delete outRelease;
    delete landscape;
    delete scene;
}

bool Game::event(QEvent *qEvent)
{
    if (qEvent->type() == QEvent::KeyPress)
    {
        tank1->setPos(200, 200);
    }
    if (qEvent->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *event = dynamic_cast<QMouseEvent *>(qEvent);
        int x = event->pos().x();
        int y = event->pos().y();
        tank2 = new Tank(x, y);
        scene->addItem(tank2);
        scene->update();

        //scene->update(0, 0, 1000, 700);
    }

    return true;
}


QGraphicsScene *Game::getScene()
{
    return scene;
}

void Game::keyPressEvent(QKeyEvent *keyEvent)
{
    int speed = 6;
    QString str = keyEvent->text();

    //stream->operator <<(str);
    std::cout << press++ << " PRESS \n";
    std::cout << str.toStdString() << "\n";

    //if (keyEvent->matches())
    {

    }
    if (keyEvent->key() == Qt::Key_D)
    {
        QPointF point = tank1->pos();
        point.setX(point.x() + speed);
        tank1->setPos(point);
    }
    if (keyEvent->key() == Qt::Key_Left)
    {
        QPointF point = tank2->pos();
        point.setX(point.x() - speed);
        tank2->setPos(point);
    }
}

void Game::keyReleaseEvent(QKeyEvent *keyEvent)
{
    QString str = keyEvent->text();
    std::cout << release++ << " Release\n";
    std::cout << str.toStdString() << "\n";
}

void Game::update()
{
    QList<QGraphicsItem* > listOfItems = scene->items();
    for (int i = 0; i < listOfItems.size(); i++)
    {
        listOfItems[i]->update();
        scene->update();
    }
    scene->update();
}

