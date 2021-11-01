#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQueryModel>

class client
{
public:
    client();
    client(QString,QString,int,int);
    int getage();
    int getid();
    QString getnom() ;
    QString getprenom();
    void setage(int);
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
private :
    QString nom,prenom;

    int age,id ;

};

#endif // CLIENT_H
