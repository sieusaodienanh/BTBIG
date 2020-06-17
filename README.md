# BTBIG
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


typedef struct employee_st{
	char name[30];
	char province[30];
	int year;
}ST;

//khai báo kiểu struct và khởi tạo một kiểu dữ liệu mới có tên gọi là ST.

void nhap (ST *a, int &n){                       //khởi tạo hàm nhập
	system("cls");                                //xóa màng hình
	for (int i=0; i<n; i++){                      //vòng lặp để lặp lại sô lượng nhân viên cần nhập trong đó n là số lượng nhân viên.   
	printf("\nNhap ten cua nhan vien :");         //xuất ra màng hình(nhập số lượng sinh viên).
	fflush(stdin);                               //xóa bộ nhớ đệm
  gets((a+i)->name);                           //nhập chuỗi kí tự ( nhập tên nhân viên). 
	printf("\nNhap tinh :");                     //xuất ra màng hình(nhập tỉnh).
	fflush(stdin);                               //xóa bộ nhớ đệm
  gets((a+i)->province);                       //nhập chuổi kí tự (nhập tỉnh).
	printf("\nNhap nam sinh :");                 //xuất ra màng hinh (nhập năm sinh).
	scanf("%d",&(a+i)->year);                    //nhâp năm sinh
    }
}

void xuat(ST *a, int n){                       // khởi tạo hàm xuất 
	system("cls");                               //xóa màng hình
	printf("\n|  NAME                          PROVINCE                      YEAR  |");      //xuất ra màng hình(name  province year).    
	for (int i=0; i<n; i++){                           //vòng lặp xuất ra màng 
    printf("\n   %-30s%-30s%d ", (a+i)->name, (a+i)->province, (a+i)->year);  //xuất ra màng hình sử dụng con trỏ trỏ tới các 
   }
}
void sapxep(ST *a, int n){                      
	system("cls");                          // xóa màng hình 
	for(int i=0; i<n-1; i++){             
		for(int j=i+1; j<n; j++){       
			if(strcmp((a+i)->province,(a+j)->province)<1){             //sắp xếp theo thứ tự z->a
				ST k=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=k;
			}
		}
	}
}
int timkiem(ST *a, int n){
	system("cls");
	char d[20];
	int dem=0,b=0;
	printf("\nnhap tinh nhan vien can tim kiem:");
	fflush(stdin);
	gets(d);                        //nhập tỉnh cần tìm kiếm 
	for(int i=0; i<n; i++){
		if(strcmp(d,(a+i)->province)==0){                //so sánh giá trị nhâp bằng giá trị đã cho có bằng nhau không  
			dem++;                                   //bằng nhau thì dem tăng lên
			b++;                   // dùng b để in ra tỉnh này có nhân viên hay không và nếu có thì số nhân viên bằng dem++
	    }
    }
    if(b++){
        printf("\ntinh %s co %d nhan vien",d,dem);                
    }
    else{
    	printf("\nkhong co tinh nay...");
	}
}
void luufile(ST *a, int n){
	system("cls");
    FILE * fp;               // tạo file bằng kiểu con trỏ FILE
    fp = fopen ("employee.dat","ab");  //mở file
    fprintf(fp, "\n%-20s%-20s%-20s", "Ho Ten", "Tinh", "Nam sinh"); // ghi vào file ho ten , tinh , năm sinh
    for(int i = 0;i < n;i++){
        fprintf(fp,"\n%-20s%-20s%-20d", (a+i)->name,(a+i)->province,(a+i)->year); // ghi vào file
    }
    fclose (fp); // đóng file
}
int main(){
	int nhapso,n;
	employee_st *a;
	a=(struct employee_st*) malloc(n*sizeof(struct employee_st));  // cấp bộ nhớ động có con trỏ a
	bool DaNhap = false;                   //bool là trả về đúng sai , cho DaNhap là sai.
		printf("\nNhap so luong nhan vien:");
		scanf("%d",&n);
	while(true){                     //nếu DaNhap đúng thì nó sẻ in ra menu
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
//nếu ta nhập dữ liệu nhân viên thì nó sẻ có giá trị là đúng ta có thể thực hiện tiếp các lệnh sau,nếu chưa nhập dữ liệu thì ta không thể thự hiện các lệnh còn lại.
				printf("\nBam phim bat ky de tiep tuc...");
				getch();
				break;
			case 2:
			    if(DaNhap){                 //nếu danhap đúng thì nó sẻ in dữ liệu ra màng hình
			    	printf("\nBan da chon sap xep nhan vien theo tinh...");
			    	sapxep(a,n);
			    	system("cls");
			    	xuat(a,n);
				}
				else{                 //nếu danhap sai thì nó sẻ yêu cần bạn nhập dữ liệu.
					printf("\nHay nhap danh sach nhan vien truoc...");
				}
				printf("\nBam phim bat ky de tiep tuc...");
				getch();
				break;
		
		    case 3:
		    	if(DaNhap){     //nếu danhap đúng thì nó sẻ tìm kiếm dữ liệu trong hàm nhập và in nó ra màng hình.
		    		printf("\nBan da chon tim nhan vien theo tinh...");
		    		timkiem(a,n);
				}
				else{            / //nếu danhap sai thì nó sẻ yêu cần bạn nhập dữ liệu.
					printf("\nHay nhap danh sach nhan vien truoc...");
				}
				printf("\nBam phim bat ky de tiep tuc...");
				getch();
				break;
			case 4:
			    if(DaNhap){   //nếu danhap đúng thì nó sẻ lưu vào file
			    	printf("\nBan da chon ghi vao tep nhi phan employee.dat...");
			    	luufile(a, n);
				}
				else{    //nếu danhap sai thì nó sẻ yêu cần bạn nhập dữ liệu.
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
			default:          nếu bạn nhập giá trị khác ,1,2,3,4,5 thì chương trình yêu cầu bạn nhập lại
			    printf("\nKhong co chuc nang nay...");
				printf("\nBam phim bat ky de tiep tuc...");
				getch();
				break;	
	    }
    }
    free(a);   //giải phong bộ nhớ 
}
