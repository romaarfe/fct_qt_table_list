#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase baseDados;

    void fecharConexao()
    {
        baseDados.close();
        baseDados.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool abrirConexao()
    {
        QMessageBox mensagem;

        QSqlDatabase baseDados = QSqlDatabase::addDatabase("QSQLITE");
        baseDados.setDatabaseName("/home/administrator/Formacao/Projeto/qtBD/projeto_qt.db");

        if (!baseDados.open())
        {
            mensagem.setText("Falha ao conectar com a BD!");
            mensagem.setDefaultButton(QMessageBox::Close);
            mensagem.exec();
            return false;
        }
        else
        {
            mensagem.setText("Conectando...");
            mensagem.setDefaultButton(QMessageBox::Close);
            mensagem.exec();
            return true;
        }
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnConsultarBD_clicked();

    void on_btnConsultarNome_clicked();

    void on_btnConsultarSobrenome_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
