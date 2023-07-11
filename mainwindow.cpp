#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnConsultarBD_clicked()
{
    QMessageBox mensagem;
    QSqlQueryModel *modelo = new QSqlQueryModel();
    abrirConexao();

    QSqlQuery *consulta = new QSqlQuery(baseDados);
    consulta->prepare("SELECT nome, sobrenome FROM heroi");

    consulta->exec();

    modelo->setQuery(*consulta);

    ui->tbvTabela->setModel(modelo);

    fecharConexao();

    mensagem.setText("Retornaram os seguintes resultados: ");
    mensagem.setDefaultButton(QMessageBox::Close);
    mensagem.exec();

}

void MainWindow::on_btnConsultarNome_clicked()
{
    QMessageBox mensagem;
    QSqlQueryModel *modeloNome = new QSqlQueryModel();
    abrirConexao();

    QSqlQuery *consultaNome = new QSqlQuery(baseDados);
    consultaNome->prepare("SELECT nome FROM heroi");

    consultaNome->exec();

    modeloNome->setQuery(*consultaNome);

    ui->lstNome->setModel(modeloNome);

    fecharConexao();

    mensagem.setText("Retornaram os seguintes nomes: ");
    mensagem.setDefaultButton(QMessageBox::Close);
    mensagem.exec();
}


void MainWindow::on_btnConsultarSobrenome_clicked()
{
    QMessageBox mensagem;
    QSqlQueryModel *modeloSobrenome = new QSqlQueryModel();
    abrirConexao();

    QSqlQuery *consultaSobrenome = new QSqlQuery(baseDados);
    consultaSobrenome->prepare("SELECT sobrenome FROM heroi");

    consultaSobrenome->exec();

    modeloSobrenome->setQuery(*consultaSobrenome);

    ui->lstSobrenome->setModel(modeloSobrenome);

    fecharConexao();

    mensagem.setText("Retornaram os seguintes sobrenomes: ");
    mensagem.setDefaultButton(QMessageBox::Close);
    mensagem.exec();
}

