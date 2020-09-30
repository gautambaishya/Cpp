#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

bool next_permute(string &str)
{

    int i = str.length() - 1;
    while(i > 0)
    {
        if(str[i-1] < str[i])
        {
            break;
        }

        i--;
    }


    if(i==0)
        return false;


    int pivot = i-1;


    int j = str.length() - 1;
    while(j > pivot)
    {
        if(str[j] > str[pivot])
        {
            break;
        }

        j--;
    }

    if (j == pivot)
        return false;


    swap(str[pivot], str[j]);


    j =  str.length() - 1;
    while(i < j)
    {
        swap(str[i++], str[j--]);
    }
    return true;
}

void generate_all_permutations(string &str)
{

    sort(str.begin(), str.end());


    while(next_permute(str))
    {
        cout << str << "\n";
    }
}

int main()
{
    string word = "abcdefghijklmnopqrstuvwxyz";
    cout << word << "\n";
    string str = word;
    generate_all_permutations(str);
}

