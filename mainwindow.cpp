#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <QSql>

// Construtor da classe MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Configura a interface de utilizador para a janela principal
    ui->setupUi(this);
}

// Destrutor da classe MainWindow
MainWindow::~MainWindow()
{
    // Libera a memória alocada para o objeto de interface de utiilizador
    delete ui;
}

// Slot para consultar dados na base de dados
void MainWindow::on_btnConsultarBD_clicked()
{
    // Cria uma caixa de mensagem
    QMessageBox mensagem;

    // Cria um modelo para a tabela de consulta
    QSqlQueryModel *modelo = new QSqlQueryModel();

    // Abre a conexão com a base de dados
    abrirConexao();

    // Cria uma consulta SQL
    QSqlQuery *consulta = new QSqlQuery(baseDados);

    // Define a chave de criptografia (neste exemplo, é "teste123")
    consulta->exec("PRAGMA key = 'teste123'");

    // Prepara a consulta SQL para selecionar os campos "nome" e "sobrenome" da tabela "heroi"
    consulta->prepare("SELECT nome, sobrenome FROM heroi");

    // Executa a consulta
    consulta->exec();

    // Define o resultado da consulta como modelo para a tabela
    modelo->setQuery(*consulta);

    // Define o modelo para a tabela na interface gráfica
    ui->tbvTabela->setModel(modelo);

    // Fecha a conexão com a base de dados
    fecharConexao();

    // Exibe uma mensagem indicando que a consulta foi realizada com sucesso
    mensagem.setText("Retornaram os seguintes resultados: ");
    mensagem.exec();

}

// Slot para consultar os nomes na base de dados
void MainWindow::on_btnConsultarNome_clicked()
{
    // Cria uma caixa de mensagem
    QMessageBox mensagem;

    // Cria um modelo para a lista de nomes
    QSqlQueryModel *modeloNome = new QSqlQueryModel();

    // Abre a conexão com a base de dados
    abrirConexao();

    // Cria uma consulta SQL para selecionar apenas o campo "nome" da tabela "heroi"
    QSqlQuery *consultaNome = new QSqlQuery(baseDados);
    consultaNome->prepare("SELECT nome FROM heroi");

    // Executa a consulta
    consultaNome->exec();

    // Define o resultado da consulta como modelo para a lista de nomes
    modeloNome->setQuery(*consultaNome);

    // Define o modelo para a lista de nomes na interface gráfica
    ui->lstNome->setModel(modeloNome);


    // Fecha a conexão com a base de dados
    fecharConexao();

    // Exibe uma mensagem indicando que a consulta foi realizada com sucesso
    mensagem.setText("Retornaram os seguintes nomes: ");
    mensagem.exec();
}

// Slot para consultar os sobrenomes na base de dados
void MainWindow::on_btnConsultarSobrenome_clicked()
{
    // Cria uma caixa de mensagem
    QMessageBox mensagem;

    // Cria um modelo para a lista de sobrenomes
    QSqlQueryModel *modeloSobrenome = new QSqlQueryModel();

    // Abre a conexão com a base de dados
    abrirConexao();

    // Cria uma consulta SQL para selecionar apenas o campo "sobrenome" da tabela "heroi"
    QSqlQuery *consultaSobrenome = new QSqlQuery(baseDados);
    consultaSobrenome->prepare("SELECT sobrenome FROM heroi");

    // Executa a consulta
    consultaSobrenome->exec();

    // Define o resultado da consulta como modelo para a lista de sobrenomes
    modeloSobrenome->setQuery(*consultaSobrenome);

    // Define o modelo para a lista de sobrenomes na interface gráfica
    ui->lstSobrenome->setModel(modeloSobrenome);

    // Fecha a conexão com a base de dados
    fecharConexao();

    // Exibe uma mensagem indicando que a consulta foi realizada com sucesso
    mensagem.setText("Retornaram os seguintes sobrenomes: ");
    mensagem.exec();
}

