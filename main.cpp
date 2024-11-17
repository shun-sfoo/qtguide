#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>

// qt中 new 出来的对象， 明确了父类 无须delete

class Label : public QLabel {
public:
  Label(QWidget *parent = nullptr) : QLabel(parent) {
    setAlignment(Qt::AlignCenter);
    setStyleSheet(R"(
                  QLabel {
                  margin: 20px;
                  font-size: 40px;
                  }
                  )");
  }
};

class MainWindow : public QMainWindow {
public:
  MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) { // 委托构造器
    setWindowTitle("9x9 table");
    setCentralWidget(new QWidget);
    QGridLayout *layout = new QGridLayout;
    centralWidget()->setLayout(layout);
    for (int i = 1; i <= 9; ++i) {
      for (int j = 1; j <= 9; ++j) {
        Label *label = new Label;
        label->setText(QString("%1 * %2 = %3").arg(i).arg(j).arg(i * j));
        layout->addWidget(label, i - 1, j - 1);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow window;
  window.show();
  return app.exec();
}
