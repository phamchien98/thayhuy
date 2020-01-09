#include "vietnamese.h"
#include "generic.h"
#include "binarytree.h"
#include "nganxep.h"
#include "hangdoi.h"
#include "sort.h"
#include <stdlib.h>
#include <string.h>
typedef struct thongke{ int songuoi; char dochoi[30];} thongke;

void menu()
{
  printf("1.dang nhap\n");
  printf("2.Thoat\n");
 
 
}

void menusinhvien()
{
  
  printf("1.Xem diem\n");
  printf("2.Thay doi mat khau\n");
  printf("3. Ghi lai thong tin len file va thoat\n");
}

void menuadmin()
{
  printf("1.. Thêm một sinh viên\n");
  printf("2. in theo sap xep diem\n");
  printf("3. xoa sinh vien\n");
  printf("4. ghi ra file\n");

}

int load_db(treenode  **root){
	FILE *fp;
	fp=fopen("sinhvien.txt", "r");
	char ten[50],password[50];
	float diem;
	while(!feof(fp)){ 

		fscanf(fp,"%s %s %f%*c",ten,password,&diem);
		// printf("%s %s %f\n",ten,password,diem);
		// add node
		information info;
		strcpy(info.hoten,ten);
		strcpy(info.password,password);
		info.diem=diem;
		binaryadd(root,info);
	}

}
char ten[50],password[50];
int dangnhap(treenode  *root){
	
	printf("nhap ten: ");
	scanf("%s%*c",ten);
	printf("nhap password: ");
	scanf("%s%*c",password);
	if(strcmp(ten,"Admin")==0){

		
		information info;
		strcpy(info.hoten,ten);
		treenode* adminnode=binarysearch(root,info);
		// printf("du lieu trong cay %s %s %f\n",(*adminnode).info.hoten,(*adminnode).info.password,(*adminnode).info.diem);
		
		if (strcmp((*adminnode).info.password,password)==0)
			return 1;// 1 la dung password
		else
			return 2;//2 la sai password
		
	}
	else{
		information info;
		strcpy(info.hoten,ten);
		treenode* sinhviennode=binarysearch(root,info);
		if (sinhviennode==NULL){
			return 3;
		}
		if (strcmp((*sinhviennode).info.password,password)==0)
			return 4;/// dung thong password va ten dang nhap 
		else
			return 5;// passsword sai, ten dang nhap dung
	}
}




void addsinhvien(treenode **root){
	char ten[50],password[50];
	float diem;
	printf("nhap ten: ");
	scanf("%s%*c",ten);
	printf("nhap password: ");
	scanf("%s%*c",password);
	printf("nhap diem: ");
	scanf("%f%*c",&diem);

	information info;
	strcpy(info.hoten,ten);
	strcpy(info.password,password);
	info.diem=diem;
	binaryadd(root,info);

	return;
}
int main()
{
  // chiem ham la nguoi yeu hung
	printf("neu tach mon thi chia tay nhe !!!");
	printf("toi may em khong di day thi minh di choi nhe nhe !!!");
	printf("anh nghi anh nen doi luong !!!");


  treenode  *root=NULL;
  load_db(&root);
  printtreee(root);
  int count=0;

  int choose=0,choose_sv=0,choose_admin=0;
     do{
      menu();
      scanf("%d%*c",&choose);
      if (choose==1){
      	// xu ly dang nhap
      	int ketquadangnhap=dangnhap(root);
      	if(ketquadangnhap==1){
      		printf("chao mung admin\n");
      		do{
	      		
	      		menuadmin();
	      		scanf("%d%*c",&choose_admin);
	      		if(choose_admin==1){
	      			// them sinhvien
	      			addsinhvien(&root);
	      			// printf("_______\n");
	      			// printtreee(root);

	      		}
	      		else if (choose_admin==2){
	      			printtreee_byscore(root);
	      		}
	      		else if (choose_admin==3){
	      			printf("_____\n");
	      			char hoten[50];
	      			printf("nhap ten: ");
	      			scanf("%s%*c",hoten);
	      			if(strcmp(hoten,"Admin")==0){
	      				printf("khong cho xoa\n");
	      			}
	      			else{
	      				information info;
	      				information trave;

	      				
	      				
	      				strcpy(info.hoten,hoten);
	      				treenode* match_node=binarysearch_phanbiethoatthuong(root,info);
	      				if (match_node==NULL){
	      					printf("khong tim thay tai khoan\n");
	      				}
	      				else{
	      					printtreee_byscore(root);
	      					printf("========\n");
	      					binarydelete(&root,info,&trave);
	      					printtreee_byscore(root);
	      				}
	      				
	      			}

	      			
	      		}
	      		else if (choose_admin==4){
	      			FILE *fout=fopen("sinhvien_2.txt", "w");
	      			fprinttreee(root,fout);
	      			fclose (fout);
	      			break;
	      		}
      		}while(choose_admin!=4);

      	}
      	else if(ketquadangnhap==2){
      		printf("admin nhap sai password\n");
      		count++;

      	}
      	else if(ketquadangnhap==3){
      		printf("khong ton tai ten dang nhap dung\n");
      		count++;

      	}
      	else if(ketquadangnhap==4){
      		
      		do{
      			printf("chao mung sinhvien\n");
	      		menusinhvien();
	      		scanf("%d%*c",&choose_sv);
      			if(choose_sv==1)
	      		{
	      			information info;
	      			strcpy(info.hoten,ten);
	      			treenode* node_sv = binarysearch(root,info);
	      			printf("%f \n",(*node_sv).info.diem);

	      		}
	      		else 
	      		if (choose_sv==2)
	      		{
	      			char password_new1[50];
	      			char password_new2[50];
	      			printf("Nhap mat khau moi:\n");
	      			scanf("%s%*c",password_new1);
	      			printf("Nhap lai mat khau moi:\n");
	      			scanf("%s%*c",password_new2);
	      			if(strcmp(password_new1,password_new2)!=0)
	      			{
	      				printf("Mat khau ko khop\n");
	      			}
	      			else {

		      			information info;
		      			strcpy(info.hoten,ten);
		      			treenode* node_sv = binarysearch(root,info);
	      				strcpy((*node_sv).info.password,password_new1);
	      				printtreee(root);
	      			}
	      		}

	      		else
	      		if(choose_sv==3)
	      		{
	      			FILE *fout=fopen("sinhvien_3.txt", "w");
	      			fprinttreee(root,fout);
	      			fclose (fout);
		      		break;
	      		}
      		}
      		while(1);
      		

      	}
      	else if(ketquadangnhap==5){
      		printf("password bi sai\n");
      		count++;

      	}

      	if(count==3)
      		{break;}

      }
      else
      	if(choose==2){
      		// thoat
      		break;
      	}
      	else{
      		printf("khong hop le");
      	}


     }while (1);
  return 0;	
}
