#include "historique.h"

Historique::Historique()
{


}

void Historique::saveajouter()
{
    QFile file (":/img/img/Historique.txt");
     if (file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
     {
         // code si l'ouverture fonctionne
     QTextStream out(&file);


     out<<"un ajout effectuer"<<endl;
file.close();
     }
}
void Historique::savemodifier()
{
    QFile file (":/img/img/Historique.txt");
     if (file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
     {
         // code si l'ouverture fonctionne
     QTextStream out(&file);


     out<<"une modification effectuer"<<endl;
file.close();
     }
}
void Historique::savesupp()
{
    QFile file (":/img/img/Historique.txt");
     if (file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
     {
         // code si l'ouverture fonctionne
     QTextStream out(&file);


     out<<"une suppression effectuer"<<endl;
file.close();
     }
}
