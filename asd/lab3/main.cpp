#include <iostream>
#include <string>

std::string supermath(std::string d) {
    int a, b, c, y, iii, jjj;
    a = 0;
    b = 0;
    c = 0;
    y = 1;
    jjj = 1;
    iii = 1;
    for (int i = 0; i < d.length(); i++) {
        if (d[i] == ')') {
            for (int j = i - 1; j > -1; j--) {
                if (d[j] == '(') {
                    std::string dop;
                    for (int foo = j + 1; foo < i; foo++) {
                        dop.push_back(d[foo]);
                    }
                    dop = supermath(dop);
                    d.erase(j, i - j + 1);
                    d.insert(j, dop);
                    dop.clear();

                    i = 0;
                    j = -2;
                }
            }
        }
    }
    for (int i = 0; i < d.length(); i++) {
        if (d[i] == '*' || d[i] == '/') {
            for (int j = i - 1; j > -1; j--) {
                if (d[j] == '1' || d[j] == '2' || d[j] == '1' || d[j] == '3' || d[j] == '4' || d[j] == '5' || d[j] == '6' || d[j] == '7' || d[j] == '8' || d[j] == '9' || d[j] == '0') {
                    a = a + ((int)d[j] - 48) * y;
                    y = y * 10;
                    iii = j;
                }
                else {
                    y = 1;
                    j = -2;
                }
            }
            for (int j = i + 1; j < d.length(); j++) {
                if (d[j] == '1' || d[j] == '2' || d[j] == '1' || d[j] == '3' || d[j] == '4' || d[j] == '5' || d[j] == '6' || d[j] == '7' || d[j] == '8' || d[j] == '9' || d[j] == '0') {
                    b = b * 10 + ((int)d[j] - 48);
                    jjj = j;
                }
                else {
                    j = d.length() + 1;
                }
            }
            if (d[i] == '*') {
                c = a * b;
            }
            if (d[i] == '/') {
                c = a / b;
            }
            std::string cc = std::to_string(c);
            d.erase(iii, jjj - iii + 1);
            d.insert(iii, cc);
            a = 0;
            b = 0;
            c = 0;
            y = 1;
            jjj = 1;
            iii = 1;
            i = 0;

        }
    }
    for (int i = 0; i < d.length(); i++) {
        if (d[i] == '+' || d[i] == '-') {
            for (int j = i - 1; j > -1; j--) {
                if (d[j] == '1' || d[j] == '2' || d[j] == '1' || d[j] == '3' || d[j] == '4' || d[j] == '5' || d[j] == '6' || d[j] == '7' || d[j] == '8' || d[j] == '9' || d[j] == '0') {
                    a = a + ((int)d[j] - 48) * y;
                    y = y * 10;
                    iii = j;
                }
                else {
                    y = 1;
                    j = -2;
                }
            }
            for (int j = i + 1; j < d.length(); j++) {
                if (d[j] == '1' || d[j] == '2' || d[j] == '1' || d[j] == '3' || d[j] == '4' || d[j] == '5' || d[j] == '6' || d[j] == '7' || d[j] == '8' || d[j] == '9' || d[j] == '0') {
                    b = b * 10 + ((int)d[j] - 48);
                    jjj = j;
                }
                else {
                    j = d.length() + 1;
                }
            }
            if (d[i] == '+') {
                c = a + b;
            }
            if (d[i] == '-') {
                c = a - b;
            }
            std::string cc = std::to_string(c);
            d.erase(iii, jjj - iii + 1);
            d.insert(iii, cc);
            a = 0;
            b = 0;
            c = 0;
            y = 1;
            jjj = 1;
            iii = 1;
            i = 0;

        }
    }
    return(d);
}



int superproverka(std::string d) {
    int a = 0;
    if (d[d.length() - 1] != '=') {
        a++;
        return (a);
    }
    if (d[0] != '(' && d[0] != '0' && d[0] != '1' && d[0] != '2' && d[0] != '3' && d[0] != '4' && d[0] != '5' && d[0] != '6' && d[0] != '7' && d[0] != '8' && d[0] != '9') {
        a++;
        return (a);
    }
    for (int i = 1; i < d.length() - 1; i++) {
        if (d[i] == '+' || d[i] == '-' || d[i] == '*' || d[i] == '/') {
            if (d[i + 1] == '1' || d[i + 1] == '2' || d[i + 1] == '3' || d[i + 1] == '4' || d[i + 1] == '5' || d[i + 1] == '6' || d[i + 1] == '7' || d[i + 1] == '8' || d[i + 1] == '9' || d[i + 1] == '0' || d[i + 1] == '(') {

            }
            else {
                a++;

                return (a);
            }
            if (d[i - 1] == '1' || d[i - 1] == '2' || d[i - 1] == '3' || d[i - 1] == '4' || d[i - 1] == '5' || d[i - 1] == '6' || d[i - 1] == '7' || d[i - 1] == '8' || d[i - 1] == '9' || d[i - 1] == '0' || d[i - 1] == ')') {

            }
            else {
                a++;

                return (a);
            }
        }
        if (d[i] == '(') {
            if (d[i + 1] == '1' || d[i + 1] == '2' || d[i + 1] == '3' || d[i + 1] == '4' || d[i + 1] == '5' || d[i + 1] == '6' || d[i + 1] == '7' || d[i + 1] == '8' || d[i + 1] == '9' || d[i + 1] == '0' || d[i + 1] == '(') {

            }
            else {
                a++;

                return (a);
            }
            if (d[i - 1] == '+' || d[i - 1] == '-' || d[i - 1] == '*' || d[i - 1] == '/' || d[i - 1] == '(') {

            }
            else {
                a++;

                return (a);
            }
        }
        if (d[i] == ')') {
            if (d[i - 1] == '1' || d[i - 1] == '2' || d[i - 1] == '3' || d[i - 1] == '4' || d[i - 1] == '5' || d[i - 1] == '6' || d[i - 1] == '7' || d[i - 1] == '8' || d[i - 1] == '9' || d[i - 1] == '0' || d[i - 1] == ')') {

            }
            else {
                a++;

                return (a);
            }
            if (d[i + 1] == '+' || d[i + 1] == '-' || d[i + 1] == '*' || d[i + 1] == '/' || d[i + 1] == ')' || d[i + 1] == '=') {

            }
            else {
                a++;

                return (a);
            }
        }
        if (d[i] == '/')
        {
            if (d[i + 1] == '0')
            {
                a++;

                return (a);
            }
        }
    }
    for (int i = 0; i < d.length(); i++) {
        int jo = 0;
        int  ko = 0;
        if (d[i] == '(') {
            a++;
        }
        if (d[i] == ')') {
            a--;
        }
    }
    return a;
}




int main()
{
    std::string dd;
    std::cin >> dd;
    int a = superproverka(dd);

    if (a == 0) {


        std::cout << dd;
        dd = supermath(dd);
        dd.erase(dd.length() - 1, 1);
        std::cout << dd;
    }
    else {
        std::cout << "Error!!!";
    }
}
