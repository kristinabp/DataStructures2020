#include<iostream>
#include<fstream>

//Даден е текстов файл, в който на всеки ред са записани факултетен номер, идентификатор на курс и оценка.Да се напише функция, 
//ReadAndComputeAvgGrade която намира средния успех на студент по даден факултетен номер и име на файл

float AvgGrade(int fn, std::string filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cout << "coudn't open the file";
        exit(-1);
    }

    float gradeSum = 0;
    int numberOfGrades = 0;
    while (inputFile.good())
    {
        float grade;
        std::string d;
        int sfn;
        inputFile >> sfn >> d >> grade;
        if (fn == sfn)
        {
            gradeSum += grade;
            numberOfGrades++;
        }
    }

    return gradeSum / numberOfGrades;
}

int main()
{
    std::cout << AvgGrade(10002, "file.txt") << std::endl;
    return 0;
}
