#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
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

    // Função para fechar a conexão com a base de dados
    void fecharConexao()
    {
        baseDados.close();
        baseDados.removeDatabase(QSqlDatabase::defaultConnection);
    }

    // Função para abrir a conexão com a base de dados
    bool abrirConexao()
    {
        QMessageBox mensagem;

        // Configura o tipo de base de dados para SQLite
        QSqlDatabase baseDados = QSqlDatabase::addDatabase("QSQLITE");

        // Define o caminho do ficheiro da base de dados
        baseDados.setDatabaseName("/home/administrator/Formacao/Projeto/qtBD/projeto_formacao.db");

        // Exibe os drivers disponíveis para a base de dados
        qDebug() << QSqlDatabase::drivers();

        // Tenta abrir a conexão com a base de dados
        if (!baseDados.open())
        {
            mensagem.setText("Falha ao conectar com a BD!");
            mensagem.exec();
            return false;
        }
        else
        {
            mensagem.setText("Conectando...");
            mensagem.exec();
            return true;
        }
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slot para consultar dados na base de dados
    void on_btnConsultarBD_clicked();

    // Slot para consultar dados na base de dados por nome
    void on_btnConsultarNome_clicked();

    // Slot para consultar dados na base de dados por sobrenome/apelido
    void on_btnConsultarSobrenome_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
