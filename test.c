#include "vietnamese.h"
#include "generic.h"
#include "binarytree.h"
#include "nganxep.h"
#include "hangdoi.h"
#include "sort.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct thongke{ int songuoi; char dochoi[30];} thongke;

void menu()
{
  printf("1.nap tu dien\n");
  printf("2.noi dung tu dien\n");
  printf("3.Them sua tu\n");
  printf("4.Dich cau anh viet\n");
  printf("5.Thoat\n");
  printf("Choose:");
 
 
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
	fp=fopen("dict.txt", "r");
	char tienganh[50],tiengviet[50];
	float diem;
	int i;
	while(!feof(fp)){ 

		fscanf(fp,"%s %s%*c",tienganh,tiengviet);
		if(feof(fp)){
			break;
		}
		for (i=0; i<strlen(tiengviet);i++){
			if(tiengviet[i]=='_'){
				tiengviet[i]=' ';
			}
		}
		printf("%s %s\n",tienganh,tiengviet);
		// add node
		information info;
		strcpy(info.tienganh,tienganh);
		strcpy(info.tiengviet,tiengviet);
		binaryadd(root,info);
		if(feof(fp)){
			break;
		}
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


  treenode  *root=NULL;
  
  int count=0;

  int choose=0,choose_sv=0,choose_admin=0;
  char yes_no;
  char tutienganhmoi[50],tutiengvietmoi[50];
  char cautienganh[2000],token[30];
  int tokenindex=0;
  int chieudaicau=0;

  int cothedichduochet=1;
  int i=0;
     do{
      menu();
      scanf("%d%*c",&choose);
      if (choose==1){
		load_db(&root);
		// printtreee(root);
      }
      else
      if(choose==2){
      	if(root==NULL){
      		printf("Ban phai nap tu dien truoc tien\n");
      	}
      	else{
      		printtreee(root);
      	}
      	
      	
      }
      else
      if(choose==3){
      	printf("nhap vao tu tieng anh: ");
      	scanf("%s%*c",tutienganhmoi);
      	information info;
      	strcpy(info.tienganh,tutienganhmoi);
      	treenode* matchnode=binarysearch(root,info);
      	if(matchnode==NULL){
      		// them tu moi vao tu diem
      		printf("them nghia cua tu:");
      		scanf("%s%*c",tutiengvietmoi);
      		information info;
      		strcpy(info.tienganh,tutienganhmoi);
      		strcpy(info.tiengviet,tutiengvietmoi);
      		binaryadd(&root,info);

      	}
      	else{
      		printf("ban co muon sua nghia khong (y/n): ");
      		scanf("%c%*c",&yes_no);
      		if(yes_no=='y'||yes_no=='Y'){
      			printf("cap nhat nghia cua tu:");
      			scanf("%s%*c",tutiengvietmoi);
      			printtreee(root);
      			printf("-------update---\n");
      			strcpy((*matchnode).info.tiengviet,tutiengvietmoi);
      			printtreee(root);
      		}
      		else{
      			printf("khong cap nhat\n");
      		}
      	}
      }
      else
      if(choose==4){
      	//input string
      	scanf("%[^\n]%*c",cautienganh);
      	// chuan hoa ve dang viet thuong
      	for(int i = 0; cautienganh[i]; i++){
		    cautienganh[i] = tolower(cautienganh[i]);
		 }
		// khoi tao token la 1 string rong
      	token[0]='\0';
      	chieudaicau=strlen(cautienganh);
      	// them  dau cach vao cuoi cau 
      	cautienganh[chieudaicau+1]='\0';
      	cautienganh[chieudaicau]=' ';
      	for(i=0;i<strlen(cautienganh);i++){
      		// printf("%d\n",i );	
      		if(cautienganh[i]==' '){
      			token[tokenindex]='\0';
      			printf("%s\n", token);
      			tokenindex=0;
      		}
      		else{
      			token[tokenindex]=cautienganh[i];
      			tokenindex++;
      		}
      	}
      	printf("\n");
      	for(i=0;i<strlen(cautienganh);i++){
      		// printf("%d\n",i );	
      		if(cautienganh[i]==' '){
      			token[tokenindex]='\0';
      			// printf("%s\n", token);
      			information info;
		      	strcpy(info.tienganh,token);
		      	treenode* match_node_dich_cau=binarysearch(root,info);
	      		if(match_node_dich_cau==NULL){
	      			printf("<thieu tu> ");
	      		}
	      		else{
	      			printf("%s ",(*match_node_dich_cau).info.tiengviet);
	      		}
      		
      			tokenindex=0;
      		}
      		else{
      			token[tokenindex]=cautienganh[i];
      			tokenindex++;
      		}
      	}
      	printf("\n");

      	
      	
      }
      else
      if(choose==5){
      	// delte cay
      	freetree(&root);
      	break;
      	
      }



     }while (1);
  return 0;	
}

