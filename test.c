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
	while(!feof(fp)){ 

		fscanf(fp,"%s %s%*c",tienganh,tiengviet);
		if(feof(fp)){
			break;
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
      	printtreee(root);
      	
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
      	break;
      	
      }



     }while (1);
  return 0;	
}


// int main()
// {
//   // chiem ham la nguoi yeu hung


//   treenode  *root=NULL;
//   load_db(&root);
//   printtreee(root);
//   int count=0;

//   int choose=0,choose_sv=0,choose_admin=0;
//      do{
//       menu();
//       scanf("%d%*c",&choose);
//       if (choose==1){
//       	// xu ly dang nhap
//       	int ketquadangnhap=dangnhap(root);
//       	if(ketquadangnhap==1){
//       		printf("chao mung admin\n");
//       		do{
	      		
// 	      		menuadmin();
// 	      		scanf("%d%*c",&choose_admin);
// 	      		if(choose_admin==1){
// 	      			// them sinhvien
// 	      			addsinhvien(&root);
// 	      			// printf("_______\n");
// 	      			// printtreee(root);

// 	      		}
// 	      		else if (choose_admin==2){
// 	      			printtreee_byscore(root);
// 	      		}
// 	      		else if (choose_admin==3){
// 	      			printf("_____\n");
// 	      			char hoten[50];
// 	      			printf("nhap ten: ");
// 	      			scanf("%s%*c",hoten);
// 	      			if(strcmp(hoten,"Admin")==0){
// 	      				printf("khong cho xoa\n");
// 	      			}
// 	      			else{
// 	      				information info;
// 	      				information trave;

	      				
	      				
// 	      				strcpy(info.hoten,hoten);
// 	      				treenode* match_node=binarysearch_phanbiethoatthuong(root,info);
// 	      				if (match_node==NULL){
// 	      					printf("khong tim thay tai khoan\n");
// 	      				}
// 	      				else{
// 	      					printtreee_byscore(root);
// 	      					printf("========\n");
// 	      					binarydelete(&root,info,&trave);
// 	      					printtreee_byscore(root);
// 	      				}
	      				
// 	      			}

	      			
// 	      		}
// 	      		else if (choose_admin==4){
// 	      			FILE *fout=fopen("sinhvien_2.txt", "w");
// 	      			fprinttreee(root,fout);
// 	      			fclose (fout);
// 	      			break;
// 	      		}
//       		}while(choose_admin!=4);

//       	}
//       	else if(ketquadangnhap==2){
//       		printf("admin nhap sai password\n");
//       		count++;

//       	}
//       	else if(ketquadangnhap==3){
//       		printf("khong ton tai ten dang nhap dung\n");
//       		count++;

//       	}
//       	else if(ketquadangnhap==4){
      		
//       		do{
//       			printf("chao mung sinhvien\n");
// 	      		menusinhvien();
// 	      		scanf("%d%*c",&choose_sv);
//       			if(choose_sv==1)
// 	      		{
// 	      			information info;
// 	      			strcpy(info.hoten,ten);
// 	      			treenode* node_sv = binarysearch(root,info);
// 	      			printf("%f \n",(*node_sv).info.diem);

// 	      		}
// 	      		else 
// 	      		if (choose_sv==2)
// 	      		{
// 	      			char password_new1[50];
// 	      			char password_new2[50];
// 	      			printf("Nhap mat khau moi:\n");
// 	      			scanf("%s%*c",password_new1);
// 	      			printf("Nhap lai mat khau moi:\n");
// 	      			scanf("%s%*c",password_new2);
// 	      			if(strcmp(password_new1,password_new2)!=0)
// 	      			{
// 	      				printf("Mat khau ko khop\n");
// 	      			}
// 	      			else {

// 		      			information info;
// 		      			strcpy(info.hoten,ten);
// 		      			treenode* node_sv = binarysearch(root,info);
// 	      				strcpy((*node_sv).info.password,password_new1);
// 	      				printtreee(root);
// 	      			}
// 	      		}

// 	      		else
// 	      		if(choose_sv==3)
// 	      		{
// 	      			FILE *fout=fopen("sinhvien_3.txt", "w");
// 	      			fprinttreee(root,fout);
// 	      			fclose (fout);
// 		      		break;
// 	      		}
//       		}
//       		while(1);
      		

//       	}
//       	else if(ketquadangnhap==5){
//       		printf("password bi sai\n");
//       		count++;

//       	}

//       	if(count==3)
//       		{break;}

//       }
//       else
//       	if(choose==2){
//       		// thoat
//       		break;
//       	}
//       	else{
//       		printf("khong hop le");
//       	}


//      }while (1);
//   return 0;	
// }
