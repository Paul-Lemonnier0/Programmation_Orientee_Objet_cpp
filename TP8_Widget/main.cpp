#include "calcul.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    calcul fenetre;
    fenetre.show();
    return app.exec();
}
