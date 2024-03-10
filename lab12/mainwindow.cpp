#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QSlider>

void MainWindow::showMsg(){
    QMessageBox* msg = new QMessageBox();
    msg->setText("Кнопка нажата!");
    msg->exec();
}

void MainWindow::menu(){


    QMenu* media = menuBar()->addMenu("Медиа");
    QMenu* playback = menuBar()->addMenu("Воспроизведение");
    QMenu* audio = menuBar()->addMenu("Аудио");
    QMenu* video = menuBar()->addMenu("Видео");
    QMenu* sub = menuBar()->addMenu("Субтитры");
    QMenu* instruments = menuBar()->addMenu("Инструменты");
    QMenu* view = menuBar()->addMenu("Вид");
    QMenu* help = menuBar()->addMenu("Помощь");

    QPixmap openfpix(":/img/file_icon.png");
    auto* openf = new QAction(openfpix,"Открыть файл...", this);
    openf->setShortcut(tr("Ctrl+O"));
    media->addAction(openf);
    connect(openf,SIGNAL(triggered()),this,SLOT(showMsg()));


    QPixmap openflspix(":/img/file_icon.png");
    auto* openfls = new QAction(openflspix,"Открыть файлы...", this);
    openfls->setShortcut(tr("Ctrl+Shift+O"));
    media->addAction(openfls);
    connect(openfls,SIGNAL(triggered()),this,SLOT(showMsg()));

    QPixmap opendirpix(":/img/file_icon.png");
    auto* opendir = new QAction(opendirpix,"Открыть папку...", this);
    opendir->setShortcut(tr("Ctrl+F"));
    media->addAction(opendir);
    connect(opendir,SIGNAL(triggered()),this,SLOT(showMsg()));

    QPixmap opendiskpix(":/img/disk_icon.png");
    auto* opendisk = new QAction(opendiskpix,"Открыть диск...", this);
    opendisk->setShortcut(tr("Ctrl+D"));
    media->addAction(opendisk);
    connect(opendisk,SIGNAL(triggered()),this,SLOT(showMsg()));

    QPixmap openurlpix(":/img/www.png");
    auto* openurl = new QAction(openurlpix,"Открыть URL...", this);
    openurl->setShortcut(tr("Ctrl+N"));
    media->addAction(openurl);
    connect(openurl,SIGNAL(triggered()),this,SLOT(showMsg()));

    auto* opengadget = new QAction("Открыть устройство захвата...", this);
    opengadget->setShortcut(tr("Ctrl+C"));
    media->addAction(opengadget);

    auto* openadr = new QAction("Открыть адрес из буфера обмена...", this);
    openf->setShortcut(tr("Ctrl+V"));
    media->addAction(openadr);

    media->addSeparator();


    auto* save = new QAction("Открыть плейлист как...", this);
    save->setShortcut(tr("Ctrl+Y"));
    media->addAction(save);

    auto* convert = new QAction("Конвертировать/сохранить...", this);
    convert->setShortcut(tr("Ctrl+R"));
    media->addAction(convert);

    auto* pass = new QAction("Передавать...", this);
    media->addAction(pass);

    media->addSeparator();

    auto* ex = new QAction("Выход по окончании плейлиста...", this);
    ex->setShortcut(tr("Ctrl+S"));
    media->addAction(ex);

    QPixmap exitpix(":/img/exit_icon.png");
    auto* exit = new QAction(exitpix,"Выход...", this);
    exit->setShortcut(tr("Ctrl+Q"));
    media->addAction(exit);



    QPixmap plbckpix(":/img/play-button-arrowhead.png");
    auto* plbck = new QAction(plbckpix,"Воспроизвести", this);
    playback->addAction(plbck);

    QPixmap stoppix(":/img/stop.png");
    auto* stop = new QAction(stoppix,"Стоп", this);
    playback->addAction(stop);

    QPixmap prevpix(":/img/free-icon-rewind-7881840.png");
    auto* prev = new QAction(prevpix,"Предыдущий", this);
    playback->addAction(prev);

    QPixmap nextpix(":/img/free-icon-fast-forward-7881795.png");
    auto* next = new QAction(nextpix,"Следующий", this);
    playback->addAction(next);

    QPixmap recordpix(":/img/dot_icon.png");
    auto* record = new QAction(recordpix,"Воспроизвести...", this);
    playback->addAction(record);




    auto* audioroad = new QAction("Аудиодорожка", this);
    audio->addAction(audioroad);

    auto* audiogadget = new QAction("Аудиоустройство", this);
    audio->addAction(audiogadget);


    auto* stereo = new QAction("Режим стерео", this);
    audio->addAction(stereo);

    audio->addSeparator();

    auto* visualization = new QAction("Визуализация", this);
    audio->addAction(visualization);

    audio->addSeparator();


    QPixmap v_uppix(":/img/v_up_icon.png");
    auto* v_up = new QAction(v_uppix,"Увеличить громкость", this);
    audio->addAction(v_up);

    QPixmap v_downpix(":/img/v_down_icon.png");
    auto* v_down = new QAction(v_downpix,"Уменьшить громкость", this);
    audio->addAction(v_down);

    QPixmap mutepix(":/img/mute_icon.png");
    auto* mute = new QAction(mutepix,"Выключить звук", this);
    audio->addAction(mute);




    auto* videoroad = new QAction("Видеодорожка", this);
    video->addAction(videoroad);


    video->addSeparator();

    auto* bigsreen = new QAction("Во весь экран", this);
    video->addAction(bigsreen);

    auto* fit = new QAction("Подогнать под окно", this);
    video->addAction(fit);

    auto* background = new QAction("Фон рабочего стола", this);
    video->addAction(background);

    video->addSeparator();

    auto* scale = new QAction("Масштаб", this);
    video->addAction(scale);

    auto* aspect_ratio = new QAction("Соотношение сторон", this);
    video->addAction(aspect_ratio);

    auto* framing = new QAction("Кадрирование", this);
    video->addAction(framing);

    video->addSeparator();

    auto* elimination_of_interlacing = new QAction("Устранение чересстрочности", this);
    video->addAction(elimination_of_interlacing);

    auto* elimination_mode = new QAction("Режим устранения", this);
    video->addAction(elimination_mode);

    video->addSeparator();

    auto* make_screen = new QAction("Сделать снимок", this);
    video->addAction(make_screen);





    auto* add_sub = new QAction("Добавить файл субтитров", this);
    sub->addAction(add_sub);



    QPixmap effects_and_filterspix(":/img/filters_icon.png");
    auto* effects_and_filters = new QAction(effects_and_filterspix,"Эффекты и фильтры", this);
    effects_and_filters->setShortcut(tr("Ctrl+E"));
    instruments->addAction(effects_and_filters);

    auto* sync = new QAction("Синхронизация дорожек", this);
    instruments->addAction(sync);

    auto* media_inf = new QAction("Информация о медиафайле", this);
    media_inf->setShortcut(tr("Ctrl+I"));
    instruments->addAction(media_inf);

    auto* codec_inf = new QAction("Информация о кодеке", this);
    codec_inf->setShortcut(tr("Ctrl+J"));
    instruments->addAction(codec_inf);

    auto* conf_vlm = new QAction("Конфигурация VLM", this);
    conf_vlm->setShortcut(tr("Ctrl+Shift+W"));
    instruments->addAction(conf_vlm);

    auto* guide = new QAction("Гид по программам(EPG)", this);
    instruments->addAction(guide);

    auto* messages = new QAction("Сообщения", this);
    messages->setShortcut(tr("Ctrl+M"));
    instruments->addAction(messages);

    auto* modules = new QAction("Модули и расширения", this);
    instruments->addAction(modules);

    instruments->addSeparator();

    QPixmap interface_settingspix(":/img/settings_icon.png");
    auto* interface_settings = new QAction(interface_settingspix,"Настройка интерфейса", this);
    instruments->addAction(interface_settings);

    QPixmap settingspix(":/img/settings_icon.png");
    auto* settings = new QAction(settingspix,"Настройка интерфейса", this);
    settings->setShortcut(tr("Ctrl+P"));
    instruments->addAction(settings);




    auto* playlist = new QAction("Плейлист", this);
    view->addAction(playlist);

    auto* integr_playlist = new QAction("Встроенный плейлист", this);
    view->addAction(integr_playlist);

    view->addSeparator();

    auto* over_wind = new QAction("Поверх всех окон", this);
    view->addAction(over_wind);

    view->addSeparator();

    auto* mini_interface = new QAction("Мини-интерфейс", this);
    view->addAction(mini_interface );

    auto* full_screen = new QAction("Полноэкранный режим", this);
    view->addAction(full_screen);

    auto* extra_el = new QAction("Доп. элементы управления", this);
    view->addAction(extra_el);

    auto* status_bar = new QAction("Строка состояния", this);
    view->addAction(status_bar);

    view->addSeparator();

    auto* add_interface = new QAction("Добавить интерфейс", this);
    view->addAction(add_interface);

    view->addSeparator();

    auto* vlub = new QAction("VLub", this);
    view->addAction(vlub);



    auto* help_act = new QAction("Помощь", this);
    help->addAction(help_act);

    auto* check_upd = new QAction("Проверить обновления", this);
    help->addAction(check_upd);

    view->addSeparator();

    auto* about = new QAction("О программе", this);
    help->addAction(about);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Медиапроигрыватель");
    this->resize(1280,720);
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* vlayout = new QVBoxLayout(centralWidget);

    menu();

    QLabel* label = new QLabel("");
    label->setPixmap(QPixmap (":/img/VLC-Logo.png"));
    label->setScaledContents( true );
    label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    QHBoxLayout* first_layout = new QHBoxLayout();
    first_layout->addWidget(label);
    vlayout->addLayout(first_layout);





    QHBoxLayout* second_layout = new QHBoxLayout();
    QLabel* time1 = new QLabel("--+--");
    second_layout->addWidget(time1);
    time1->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
    QSlider* progress = new QSlider(Qt::Orientation::Horizontal);
    second_layout->addWidget(progress);
    progress->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
    QLabel* time2 = new QLabel("--+--");
    second_layout->addWidget(time2);
    time2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
    vlayout->addLayout(second_layout);


    QHBoxLayout* third_layout = new QHBoxLayout();

    QPushButton* start_btn = new QPushButton();
    start_btn->setIcon(QIcon(":/img/play-button-arrowhead.png"));
    third_layout->addWidget(start_btn);

    QPushButton* back_btn = new QPushButton();
    back_btn->setIcon(QIcon(":/img/free-icon-rewind-7881840.png"));
    third_layout->addWidget(back_btn);

    QPushButton* pause_btn = new QPushButton();
    pause_btn->setIcon(QIcon(":/img/pause.png"));
    third_layout->addWidget(pause_btn);

    QPushButton* next_btn = new QPushButton();
    next_btn->setIcon(QIcon(":/img/free-icon-fast-forward-7881795.png"));
    third_layout->addWidget(next_btn);

    QPushButton* stop_btn = new QPushButton();
    stop_btn->setIcon(QIcon(":/img/stop.png"));
    third_layout->addWidget(stop_btn);

    third_layout->addSpacerItem(new QSpacerItem(40,20));


    QPushButton* mute_btn = new QPushButton();
    mute_btn->setIcon(QIcon(":/img/mute_icon.png"));
    third_layout->addWidget(mute_btn);

    QSlider* volume = new QSlider(Qt::Orientation::Horizontal);
    third_layout->addWidget(volume);


    third_layout->setStretch(0,0);
    third_layout->setStretch(1,0);
    third_layout->setStretch(2,0);
    third_layout->setStretch(3,0);
    third_layout->setStretch(4,0);
    third_layout->setStretch(5,5);
    third_layout->setStretch(6,0);
    third_layout->setStretch(7,1);
    vlayout->addLayout(third_layout);



    vlayout->setStretch(0,1);
    vlayout->setStretch(1,0);
    vlayout->setStretch(2,0);



    setCentralWidget(centralWidget);
}




MainWindow::~MainWindow()
{

}

