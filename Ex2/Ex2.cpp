//
// Created by Мария Ульянова on 19.09.2022.
//
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;




void simple_func(float* ptr_Mean_Score_massive, string* ptr_Study_Track_massive, int num_students)
{
//    //сделать из массива вектор
    vector<string*> ptr_Study_Track;//вектор указателей
    for(int i = 0; i< num_students; i++)
    {
        ptr_Study_Track.push_back((ptr_Study_Track_massive+i));
    }

    vector<float*> ptr_Mean_Score;//вектор указателей
    for(int i = 0; i< num_students; i++)
    {
        ptr_Mean_Score.push_back((ptr_Mean_Score_massive+i));
    }

    ofstream out_file;
    out_file.open ("out_file.txt");

    vector<string*>::iterator i_begin = ptr_Study_Track.begin();
    vector<string*>::iterator i_end = ptr_Study_Track.end();


    for( vector<string*>::iterator i = i_begin; i< i_end; i++)
    {
        string track_name = **i;
        int track_counter = 0;
        float mean_score = 0;

        vector<float*>::iterator k =ptr_Mean_Score.begin();
        for(vector<string*>::iterator  j = ptr_Study_Track.begin(); j < ptr_Study_Track.end(); j++)
        {
            string local_track_name = **j;
            float local_score = **k;
            if((**j).compare(track_name) == 0)
            {
                track_counter++; //считаем количество студентов
                mean_score += **(k) ;// считаем сумму средних баллов
                ptr_Study_Track.erase(j);// удалить совпадающий элемент по адресу
                ptr_Mean_Score.erase(k);
            }
            if(k< ptr_Mean_Score.end())
            {
                k++;//итератор для массива оценок
            }
        }
        mean_score = mean_score/track_counter; // считаем средний бал на направлении
        // сделать запись в файл -> название трека, число студентов, средний бал
        if (out_file.is_open())
        {
            out_file << track_name << " " << track_counter << " " << mean_score << endl;
        }

    }
    out_file.close();

}



//this function creates a new file with track name, students number for this track, and the mean score
void simple_func_2(vector<float>::iterator ptr_Mean_Score_begin,
                   vector<float>::iterator ptr_Mean_Score_end,
                   vector<string>::iterator ptr_Study_Track_begin,
                   vector<string>::iterator ptr_Study_Track_end)
{
    //open file to write in
    ofstream out_file;
    out_file.open ("out_file.txt");
    out_file << "track_name" << " " << "track_counter" << " " << "mean_score" << endl;

    for( vector<string>::iterator i = ptr_Study_Track_begin; i< ptr_Study_Track_end; i++)
    {
        string track_name = *i;
        if (track_name!=string())
        {
            int track_counter = 0;
            float mean_score = 0;
            vector<float>::iterator k = ptr_Mean_Score_begin;
            for(vector<string>::iterator  j = ptr_Study_Track_begin; j < ptr_Study_Track_end; j++)
            {
                string local_track_name = *j;
                float local_score = *k;
                if((*j).compare(track_name) == 0)
                {
                    track_counter++; //считаем количество студентов
                    mean_score += *(k) ;// считаем сумму средних баллов
                    *j = string();// зануляем просмотренный элемент
                }
                if(k < ptr_Mean_Score_end)
                {
                    k++;//итератор для массива оценок
                }
            }
            mean_score = mean_score/track_counter; // считаем средний бал на направлении
            // делаем запись в файл -> название трека, число студентов, средний бал
            if (out_file.is_open())
            {
                out_file << track_name << " " << track_counter << " " << mean_score << endl;
            }
        }
    }
    out_file.close();
}
int main()
{
//read file
    string line;
    vector<string> track_name;
    vector<float> mean_score;
    ifstream myfile ("/Users/mariaulanova/CLionProjects/Cpp-OpenCV/input_file_ex2");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            string delim(" ");
            size_t prev = 0;
            size_t next;
            size_t delta = delim.length();
            //write fio - 3 words
            for(int i = 0;i<3; i++)
            {
                next = line.find( delim, prev );
                prev = next + delta;
            }
            //write mean score - 1 float
            while( ( next = line.find( delim, prev ) ) != string::npos )
            {
                mean_score.push_back(stof(line.substr( prev, next-prev )));
                prev = next + delta;
            }
            //write track name
            track_name.push_back(line.substr( prev ) );
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    vector<string> :: iterator ptr_track_name_begin = track_name.begin();
    vector<float> :: iterator ptr_mean_score_begin = mean_score.begin();
    vector<string> :: iterator ptr_track_name_end = track_name.end();
    vector<float> :: iterator ptr_mean_score_end = mean_score.end();

    int number_students = track_name.size();


    simple_func_2(ptr_mean_score_begin, ptr_mean_score_end, ptr_track_name_begin, ptr_track_name_end);


}
//float* ptr_mean_score = ;


//string* ptr_name_fio = &name_fio;
//    string track_name[2] = {"track_number_one", "track_number_two"};
//    string* ptr_track_name = &track_name[0];
//    float score_value[2] = {5.0, 3.0};
//    float* ptr_score_value = &score_value[0];
//    int number_students = 2;
