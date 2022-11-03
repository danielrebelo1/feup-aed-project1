//
// Created by Jaime on 31/10/2022.
//

#ifndef PROJETO_AED_CURSO_H
#define PROJETO_AED_CURSO_H

#include <set>
#include <string>
#include <queue>
#include "Student.h"
#include "FileReader.h"
#include "PedidoAlteracao.h"
#include "Utils.h"
#include <algorithm>
#include "Menu.h"
#include <climits>

struct studentComparator2{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s2->get_Name() < s1->get_Name());
        return false;
    }
};

struct studentComparatorCode {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_student_Code() < s2->get_student_Code());
        return false;
    }
};

struct studentComparatorDecreasingCode {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s2->get_student_Code() < s1->get_student_Code());
        return false;
    }
};

class Curso {
    std::set<Student*, studentComparator> allStudents;
    std::set<Turma*, turmaComparator> allTurmas;
    std::queue<PedidoAlteracao* > queuePA;
public:
    Curso() = default;
    Curso(std::set<Student*, studentComparator> , std::set<Turma*, turmaComparator> );
    std::set<Student*, studentComparator> getAllStudents() const;
    std::set<Turma*, turmaComparator> getAllTurmas() const;

    void PrintStudents(std::set<Student* , studentComparator> students , char option);
    void PrintHorarioTurma(std::vector<Turma*> , std::string uc = "");
    std::vector<Turma*> FindTurma();
    Student* PrintStudentByName();
    Student* PrintStudentByCode();

    std::set<Student*, studentComparator> getStudentsTurma(std::vector<Turma*> turmas, std::string ucCode = "");

    static std::set<Student* , studentComparator2> StudentReverseSortAlpha(std::set<Student *, studentComparator> students, std::set<Student *, studentComparator2> &newstudents);
    static std::set<Student* , studentComparatorCode> StudentSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorCode> &newstudents);
    static std::set<Student* , studentComparatorDecreasingCode> StudentReverseSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorDecreasingCode> &newstudents);

    void SortbyTurmaCapacity(std::set<Turma*, turmaComparator> allTurmas , std::string ucCode , int option);
    std::set<Student* , studentComparator> getStudentsYear(std::set<Student* , studentComparator> students , int year);

    void getTurmasYear( int year = INT_MAX);

    void SortByEnrolledUC( int op = 1 , std::string ucCode= "");
    std::string ucCodeNormalizer();
    void AddPA(Student* s, Turma* t  , int typeRequest);
    Turma* FindTurmaLowestCapacity(std::string ucCode);
    Turma* GetTurma(Student* s , std::string ucCode);
    void setDefaultCap(int newCap);
    // static int defaultCap = 24;
};

#endif //PROJETO_AED_CURSO_H
