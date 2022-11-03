

#include "PedidoAlteracao.h"

using namespace std;


PedidoAlteracao::PedidoAlteracao(Student *student , Turma* turma , int typeRequest){
    this->student = student;
    this->turma = turma;
    this->typeRequest = typeRequest;
}

PedidoAlteracao::PedidoAlteracao(Student* student1, Student* student2 ,Turma *turma1 , Turma *turma2) {
    student1 = student1;
    student2 = student2;
    turma1 = turma1;
    turma2 = turma2;
}

void PedidoAlteracao::TrocaTurma(Student *student , Turma* turmaOrigem , Turma* turmaDestino) {
    if ( turmaDestino->get_nrStudentsTurma() < turmaDestino->defaultCap && (abs(turmaOrigem->get_nrStudentsTurma() - turmaDestino->get_nrStudentsTurma()) < 4)) {
        RemoveFromClass(student , turmaOrigem);
        student->UpdateTurmas(turmaDestino);
        turmaDestino->AddStudent(student);
    }
    else {
        // escrever pedido p archive
        cout << "Impossível adicionar aluno à turma desejada" << endl;
    }
}

int PedidoAlteracao::AddtoClass(Student *student1 , Turma* turma ) {
    std::list<Slot *> horarioUcTurma = turma->getHorarioUcTurma();
    std::vector< std::pair <Slot * , Turma *>> horarioStudent = student1->createHorario();
    if (turma->get_nrStudentsTurma() < turma->defaultCap && isCompatible(horarioUcTurma , horarioStudent)){
        student1->UpdateTurmas(turma);
        turma->AddStudent(student1);
        return 1;
    }
    return 0;
}


int PedidoAlteracao::RemoveFromClass(Student *student1 , Turma* turmaOrigem ) {
    student1->RemoveFromTurma(turmaOrigem);
    turmaOrigem->RemoveStudent(student1);
    return 1;
}

void PedidoAlteracao::TrocaDiretaTurma(Student *student1 , Student *student2 , Turma *turma1 , Turma *turma2){
        student1->RemoveFromTurma(turma1);
        student2->RemoveFromTurma(turma2);
        student1->UpdateTurmas(turma2);
        student2->UpdateTurmas(turma1);
        turma1->AddStudent(student2);
        turma2->AddStudent(student1);
}

Student*  PedidoAlteracao::getStudent(){return student;}
Student*  PedidoAlteracao::getStudent2(){return student2;}
Turma*  PedidoAlteracao::getTurma(){return turma;}
Turma*  PedidoAlteracao::getTurma2(){return turma2;}
int  PedidoAlteracao::getTypeRequest(){return typeRequest;}


