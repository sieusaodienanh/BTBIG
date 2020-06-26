#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


typedef struct employee_st{
	char name[30];
	char province[30];
	int year;
}ST;

void nhap (ST *a, int &n){
	system("cls");
	for (int i=0; i<n; i++){
	printf("\nNhap ten cua nhan vien :");
	fflush(stdin); gets((a+i)->name);
	printf("\nNhap tinh :");
	fflush(stdin); gets((a+i)->province);
	printf("\nNhap nam sinh :");
	scanf("%d",&(a+i)->year);
    }
}

void xuat(ST *a, int n){
	system("cls");
	printf("\n|  NAME                          PROVINCE                      YEAR  |");
	for (int i=0; i<n; i++){
    printf("\n   %-30s%-30s%d ", (a+i)->name, (a+i)->province, (a+i)->year);
   }
}
 

void sapxep(ST *a, int n){
	system("cls");
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp((a+i)->province,(a+j)->province)<1){
				ST k=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=k;
			}
		}
	}
}
void thongke(ST *a, int n){ 
	for(int i=0; i<n-1;i++){
		int dem=1; 
		for(int j=i+1;j<n;j++){
			if((strcmp(a+i)->province,(a+j)->province)==0){
				n--; 
				dem++; 
			} 
			if((strcmp(a+i)->province,(a+j)->province)!=0){
				dem=dem; 
			}
		}
		printf("\ntinh %s co %d tinh",(a+i)->province);
	}
}
int timkiem(ST *a, int n){
	system("cls");
	char d[20];
	int dem=0,b=0;
	printf("\nnhap tinh nhan vien can tim kiem:");
	fflush(stdin);
	gets(d);
	for(int i=0; i<n; i++){
		if(strcmp(d,(a+i)->province)==0){
			dem++;
			b++;
	    }
    }
    if(b++){
        printf("\ntinh %s co %d nhan vien",d,dem);
    }
    else{
    	printf("\nkhong co tinh nay...");
	}
	return 0;
}
void luufile(ST *a, int n){
	system("cls");
    FILE * fp;
    fp = fopen ("employee.dat","ab");
    fprintf(fp, "\n%-20s%-20s%-20s", "Ho Ten", "Tinh", "Nam sinh");
    for(int i = 0;i < n;i++){
        fprintf(fp,"\n%-20s%-20s%-20d", (a+i)->name,(a+i)->province,(a+i)->year);
    }
    fclose (fp);
}
int main(){
	int nhapso,n;
	employee_st *a;
	a=(struct employee_st*) malloc(n*sizeof(struct employee_st));
	bool DaNhap = false;
		printf("\nNhap so luong nhan vien:");
		scanf("%d",&n);
	while(true){
		system("cls");
		printf("\n  ____________________________________________________  ");
		printf("\n |________________________MENU________________________| ");
		printf("\n |____________1.Nhap du lieu tung nhan vien___________| ");
		printf("\n |_____2.sap xep thong ke cac nhan vien theo tinh_____| ");
		printf("\n |_____________3.tim nhan vien theo tinh______________| ");
		printf("\n |_______4.ghi vao tap tin nhi phan employee.dat______| ");
		printf("\n |______________________5.EXIT________________________| ");
		scanf("%d",&nhapso);
		switch(nhapso){
			case 1:
				printf("\nBan da con nhap du lieu tung nhan vien...");
				nhap(a,n);
				printf("\nBan da nhap thanh cong...");
				DaNhap = true;
				printf("\nBam phim bat ky de tiep tuc...");
				getch();
				break;
			case 2:
			    if(DaNhap){
			    	printf("\nBan da chon sap xep nhan vien theo tinh...");
			    	sapxep(a,n);
			    	system("cls");
			    	xuat(a,n);
				thongke(a,n);
				}
				else{
					printf("\nHay nhap danh sach nhan vien truoc...");
				}
				printf("\nBam phim bat ky de tiep tuc...");
				getch();
				break;
		
		    case 3:
		    	if(DaNhap){
		    		printf("\nBan da chon tim nhan vien theo tinh...");
		    		timkiem(a,n);
				}
				else{
					printf("\nHay nhap danh sach nhan vien truoc...");
				}
				printf("\nBam phim bat ky de tiep tuc...");
				getch();
				break;
			case 4:
			    if(DaNhap){
			    	printf("\nBan da chon ghi vao tep nhi phan employee.dat...");
			    	luufile(a, n);
				}
				else{
					printf("\nHay nhap danh sach nhan vien truoc...");
				}
				printf("\nGhi vao file employee.dat thanh cong...");
				printf("\nBam phim bat ky de tiep tuc...");
				getch();
				break;
					
			case 5:
				system("cls");
			    printf("\nBan da chon thoat chuong trinh...");
			    getch();
			    return 0;
			default:
			    printf("\nKhong co chuc nang nay...");
				printf("\nBam phim bat ky de tiep tuc...");
				getch();
				break;	
	    }
    }
    free(a);
}
