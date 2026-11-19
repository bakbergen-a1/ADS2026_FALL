/*
KBTU introduces new GPA calculation system. You’re given 
 students, their marks and number of credits for their subjects. Sort them by total GPA. It is calculated as 
 
, where 
 - student’s number of subjects, 
 - GPA and number of credits for 
-th subject respectively. GPA scale is given in the notes.

Input
First line contains one integer 
 
. Each of the next 
 lines contains information about the 
-th student: his lastname, firstname, an integer 
 
 - number of subjects for this student, then 
 marks and number of credits for each subject.

Output
You should print sorted list of students. Each student should be printed in the following format: 
 
 
. First, sort them by overall GPA in ascending order; if the GPA is equal, sort by lastname, then by firstname. GPA should be printed with three digits after decimal point.

The GPA must be printed exactly as printf("%.3f", gpa) prints it in C++ (equivalently, cout « fixed « setprecision(3) « gpa). This matters: for many students the GPA falls exactly on the rounding boundary, and other rounding rules give a different answer.

Note
A+	4.00
A	3.75
B+	3.50
B	3.00
C+	2.50
C	2.00
D+	1.50
D	1.00
F	0
Examples
Input 1
5
Issenbayev Yernur 4 A 4 D+ 2 B 3 A+ 4
Yermekbayeva Diana 3 A+ 4 B+ 3 B 1
Kadyrov Asman 2 A+ 4 A+ 4
Stepanenko Ivan 3 C+ 3 F 1 A+ 5
Bissimbayev Arystan 3 A+ 4 A+ 5 D 1
Output 1
Stepanenko Ivan 3.056
Issenbayev Yernur 3.308
Yermekbayeva Diana 3.688
Bissimbayev Arystan 3.700
Kadyrov Asman 4.000
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Student {
    string last, first;
    double gpa;
};

double getGPA(string mark) {
    if (mark == "A+") return 4.0;
    if (mark == "A") return 3.75;
    if (mark == "B+") return 3.5;
    if (mark == "B") return 3.0;
    if (mark == "C+") return 2.5;
    if (mark == "C") return 2.0;
    if (mark == "D+") return 1.5;
    if (mark == "D") return 1.0;
    return 0.0;
}

bool check(Student a, Student b) {
    if (a.gpa != b.gpa) return a.gpa < b.gpa;
    if (a.last != b.last) return a.last < b.last;
    return a.first < b.first;
}

void quickSort(Student a[], int l, int r) {
    int i = l, j = r;
    Student p = a[l + (r - l) / 2];

    while (i <= j) {
        while (check(a[i], p)) i++;
        while (check(p, a[j])) j--;

        if (i <= j) {
            Student t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }

    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

int main() {
    int n;
    cin >> n;

    Student *a = new Student[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i].last >> a[i].first;

        int k;
        cin >> k;

        double sum = 0, credits = 0;

        for (int j = 0; j < k; j++) {
            string mark;
            int c;
            cin >> mark >> c;

            sum += getGPA(mark) * c;
            credits += c;
        }

        a[i].gpa = sum / credits;
    }

    if (n > 0) quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].last << " " << a[i].first << " "
             << fixed << setprecision(3) << a[i].gpa << '\n';
    }

    delete[] a;
    return 0;
}