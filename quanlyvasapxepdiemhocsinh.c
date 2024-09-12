#include <stdio.h>
#include <string.h>
#define MAX_STUDENT 50

typedef struct Student
{
    char name[50];
    int tuoi;
    float math;
    float physic;
    float chemistry;
    float trungbinh;
} Student;

void diemtrungbinh(Student *student)
{
    student->trungbinh = (student->math + student->physic + student->chemistry) / 3.0;
}

void Nhapdanhsach(Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
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

void Indanhsach(Student students[], int n)
{
    printf("\nDanh sach hoc sinh:\n");
    printf("%-20s %-5s %-10s\n", "Ten", "Tuoi", "Diem TB");
    for (int i = 0; i < n; i++)
    {
        printf("%-5d %-20s %-5d %-10.2f\n", i + 1, students[i].name, students[i].tuoi, students[i].trungbinh);
    }
}

void Sapxepdanhsach(Student students[], int n)
{
    Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (students[i].trungbinh < students[j].trungbinh)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
void Themhocsinh(Student students[], int *n)
{
    if (*n > MAX_STUDENT)
    {
        printf("Danh sach da day, khong the them hoc sinh moi.\n");
        return;
    }
    printf(" Nhap thong tin hoc sinh moi: \n");
    printf("Ten: ");
    getchar();
    fgets(students[*n].name, sizeof(students[*n].name), stdin);
    students[*n].name[strlen(students[*n].name) - 1] = '\0';

    printf("Tuoi: ");
    scanf("%d", &students[*n].tuoi);

    printf("Diem Toan: ");
    scanf("%f", &students[*n].math);

    printf("Diem Ly: ");
    scanf("%f", &students[*n].physic);

    printf("Diem Hoa: ");
    scanf("%f", &students[*n].chemistry);

    diemtrungbinh(&students[*n]);
    (*n)++;
}
void Xoahocsinh(Student students[], int *n, int stt)
{
    if (stt < 1 || stt > *n)
    {
        printf("So thu tu khong hop le.\n");
        return;
    }
    for (int i = stt - 1; i < *n - 1; i++)
    {
        students[i] = students[i + 1];
    }
    (*n)--;
}
void Timkiemhocsinh(Student students[], int n, char ten[])
{
    int found = 0;
    printf("\nKet qua tim kiem hoc sinh ten '%s':\n", ten);
    printf("%-5s %-20s %-5s %-10s\n", "STT", "Ten", "Tuoi", "Diem TB");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(students[i].name, ten) == 0)
        {
            printf("%-5d %-20s %-5d %-10.2f\n", i + 1, students[i].name, students[i].tuoi, students[i].trungbinh);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Khong tim thay hoc sinh co ten '%s'.\n", ten);
    }
}

int main()
{
    Student students[MAX_STUDENT];
    int n;
    int choice;
    int stt;
    char ten[50];
    do
    {
        printf("Nhap so luong hoc sinh (toi da %d): ", MAX_STUDENT);
        scanf("%d", &n);
        if (n <= 0 || n > MAX_STUDENT)
        {
            printf("So luong hoc sinh khong hop le. Vui long nhap lai.\n");
        }
    } while (n <= 0 || n > MAX_STUDENT);
    Nhapdanhsach(students, n);
    do
    {
        printf("\nMenu:\n");
        printf("1. Hien thi danh sach hoc sinh\n");
        printf("2. Sap xep hoc sinh theo diem trung binh\n");
        printf("3. Them hoc sinh\n");
        printf("4. Xoa hoc sinh theo so thu tu\n");
        printf("5. Tim kiem hoc sinh\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Indanhsach(students, n);
            break;
        case 2:
            Sapxepdanhsach(students, n);
            printf("Da sap xep danh sach. \n");
            Indanhsach(students, n);
            break;
        case 3:
            Themhocsinh(students, &n);
            printf("\n Da them hoc sinh.");
            Indanhsach(students, n);
            break;
        case 4:
            Indanhsach(students, n);
            printf("Nhap so thu tu hoc sinh can xoa: ");
            scanf("%d", &stt);
            Xoahocsinh(students, &n, stt);
            printf("\n Da xoa hoc sinh.");
            Indanhsach(students, n);
            break;
        case 5:
            printf("Nhap ten hoc sinh can tim: ");
            getchar();
            fgets(ten, sizeof(ten), stdin);
            ten[strlen(ten) - 1] = '\0';
            Timkiemhocsinh(students, n, ten);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}
