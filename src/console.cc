#include <iostream>
#include <functions/functions.h>
#include <conio.h>
#define SIZE 4

using namespace std;

int get_key()
{
    int key = _getch();
    if (!key || key == 224) key = _getch();
    return key;
}

int menu1()
{
    cout << "Viewing and editing an array of functions 'Enter'" << endl;
    cout << "Exit 'Esc'" << endl;

    while (true)
    {
        int key = get_key();
        if (key == 27 || key == 13) return key;
    }
}

int menu2()
{
    cout << "\n-> following function"<<endl;
    cout << "<- previous function" << endl;
    cout << "\nDelete function 'Del'" << endl;
    cout << "Insert function 'Ins'" << endl;
    cout << "Find function with max derivative '1'" << endl;
    cout << "Clear array '2'" << endl;
    cout << "Exit 'Esc'" << endl;
    while (true)
    {
        int key = get_key();
        if (key == 27 || key == 75 || key == 77 || key == 83 || key == 82 || key == 49 || key == 50) return key;
    }
}
int main() {
    vector<FunctionPtr> functions;
    Quadratic func = Quadratic(1,1,1,1);
    Harmonic func1 = Harmonic(2,2,2,2);
    functions.push_back(make_shared<Quadratic>(func));
    functions.push_back(make_shared<Harmonic>(func1));

    FunctionsSet set = FunctionsSet(functions);
    bool is_correct = false;
    FunctionPtr function;
    while (1)
    {
        system("cls");
        int m1 = menu1();
        if (m1 == 27)break;
        int current = 0;
        while (1)
        {
            set.print_current(current);
            int m2 = menu2();
            if (m2 == 27)break;
            switch (m2)
            {
            case 75:
                if (current > 0) current--;
                break;
            case 77:
                if (current < set.get_size() - 1) current++;
                break;
            case 83:
                if (set.get_size() == 1) {
                    system("cls");
                    std::cout << "Array will is empty\n" << "Input new function: " << endl;
                    set.clear();
                    while (!is_correct) {
                        function = input(*function);
                        is_correct = 1;
                    }
                    is_correct = false;
                    set.add(current, function);
                }
                else if (current == set.get_size() - 1) {
                    set.del(current);
                    current--;
                }
                else set.del(current);
                break;
            case 50:
                set.clear();
                while (!is_correct) {
                    system("cls");
                    function = input(*function);
                    is_correct = 1;
                }
                is_correct = false;
                set.add(current, function);
                current = 0;
                break;
            case 49:
                system("cls");
                std::cout << "Function with max derivative is:\n";
                set.print_current(set.find_function_max_derivative());
                std::cout << "\nDerivative = " << set[set.find_function_max_derivative()]->getting_the_derivative();
                current = 0;
                getchar();
                break;
            case 82:
            {
                while (!is_correct) {
                    system("cls");
                    function = input(*function);
                    is_correct = 1;
                }
                is_correct = false;
                set.add(current, function);
                break;
            }
            }
        }
    }
    return 0;
}

