#include<stdio.h>
#include<string.h>
#define MAX_STUDENT 50

typedef struct Student {
    char name[50];
    int tuoi;
    float math;
    float physic;
    float chemistry;
    float trungbinh;
} Student;

void diemtrungbinh(Student *student) {
    student->trungbinh = (student->math + student->physic + student->chemistry) / 3.0;
}

void Nhapdanhsach(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho hoc sinh thu %d:\n", i + 1);

        printf("Ten: ");
        getchar(); 
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strlen(students[i].name) - 1] = '\0'; 

        printf("Tuoi: ");
        scanf("%d", &students[i].tuoi);

        printf("Diem Toan: ");
        scanf("%f", &students[i].math);

        printf("Diem Ly: ");
        scanf("%f", &students[i].physic);

        printf("Diem Hoa: ");
        scanf("%f", &students[i].chemistry);

        diemtrungbinh(&students[i]);
    }
}

void Indanhsach(Student students[], int n) {
    printf("\nDanh sach hoc sinh:\n");
    printf("%-20s %-5s %-10s\n", "Ten", "Tuoi", "Diem TB");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-5d %-10.2f\n", students[i].name, students[i].tuoi, students[i].trungbinh);
    }
}

void Sapxepdanhsach(Student students[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].trungbinh < students[j].trungbinh) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    Student students[MAX_STUDENT];
    int n;
    do {
        printf("Nhap so luong hoc sinh (toi da %d): ", MAX_STUDENT);
        scanf("%d", &n);
        if (n <= 0 || n > MAX_STUDENT) {
            printf("So luong hoc sinh khong hop le. Vui long nhap lai.\n");
        }
    } while (n <= 0 || n > MAX_STUDENT);
    Nhapdanhsach(students, n);
    Sapxepdanhsach(students, n);
    Indanhsach(students, n);

    return 0;
}
