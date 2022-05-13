#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>		//to get the current date
/*
have to make changes to all functions
have to enter arguments in all functions, for b_count, c_count and a_count
have to pass the arrays for all the functions as pointers
have to make the create data function
have to create the test cases and comment the scan and printfs
*/


typedef struct{
	char fn[20];
	char ln[20];
}full_name;

typedef struct{
	int dd;
	int mm;
	int yy;
}date;

typedef struct{
	char vaccine_name[10]; 	
	int price;				
	int quantity;			
}vaccine_info;

typedef struct{
	int b_id;	//beneficiary id
	int c_id;	//center id
	vaccine_info vac_type;
	int dose; 	//1st or 2nd dose
	date app_date; 	//appointment date
}appointment_details;

typedef struct{
	int ID;
	full_name nm;
	char gender; // f or m
	date dob;
	int no_of_doses;
}Beneficiary_data;

typedef struct{
	int ID;
	char address[50];
	char district[25];
	int pin_code;
	char center_type; //g or p
	int no_of_vaccine_types;	
	vaccine_info vaccine_type[6]; 	//each center can have 6 of these vaccines
}Center_data;



Beneficiary_data BD[15];
Center_data CD [10];
appointment_details appointments[15];
	
int b_count=0, c_count=0, a_count=0;




Beneficiary_data findBeneficiaryById(int ID){
	return BD[ID-1];
}

void addNewBeneficiary(Beneficiary_data test_BD){
	BD[b_count]=test_BD;
	b_count++;
//	BD[b_count-1].ID = b_count;
//	//scan data
//	printf("\n enter the beneficiary details:");
//	scanf("%s %s", &BD[b_count].nm.fn,BD[b_count].nm.ln);
//	scanf("%d %d %d %d", &BD[b_count].no_of_doses,& BD[b_count].dob.dd, &BD[b_count].dob.mm, &BD[b_count].dob.yy);
//	scanf("%c", &BD[b_count].gender);
}

void testAddNewBeneficiary(){
	// given: input data
	Beneficiary_data test_BD;
	test_BD.dob.dd = 7; test_BD.dob.mm =7; test_BD.dob.yy= 1997; test_BD.gender='f'; test_BD.ID=b_count+1;
	strcpy(test_BD.nm.fn ,"Ramu"); strcpy(test_BD.nm.ln , "Reddy"); test_BD.no_of_doses =0;
	
	// when: new beneficiary is added
	addNewBeneficiary(test_BD);
	
	// verify: verify the action by fetching the beneficiary by ID
	Beneficiary_data temp =	findBeneficiaryById(test_BD.ID);
	if(temp.ID == test_BD.ID && (strcmp(temp.nm.fn, test_BD.nm.fn) == 0) && (strcmp(temp.nm.ln, test_BD.nm.ln)) == 0){
		printf("Added new beneficiary \n");//print details
	} else {
		printf("Error in adding new beneficiary \n");
	}
}





Center_data findCenterById(int ID){
	return CD[ID-1];
}

void addNewCenter(Center_data test_CD){
	CD[c_count]=test_CD;
	//int no_of_vac=0;
	c_count++;
	/*CD[c_count-1].ID = c_count;
	printf("\n enter the center details:");
	scanf("%s %s", &CD[c_count].address, &CD[c_count].district);
	scanf("%d %c", &CD[c_count].pin_code, &CD[c_count].center_type);
	
	printf("Enter the no of types of vaccines");
	scanf("%d",&no_of_vac);
	CD[c_count].no_of_vaccine_types = no_of_vac;
	
	for(int i=0; i<no_of_vac; i++){
		printf("Enter the name, price and quantity of the vaccine available");
		scanf("%s %d %d", &CD[c_count].vaccine_type[i].vaccine_name, &CD[c_count].vaccine_type[i].price, &CD[c_count].vaccine_type[i].quantity);
	}*/
}

void testAddNewCenter(){
	Center_data test_CD;
	strcpy(test_CD.address,"Madhapur,Telangana"); test_CD.center_type='g'; strcpy(test_CD.district , "Rangareddy"); test_CD.ID = c_count+1;
	test_CD.no_of_vaccine_types=2; test_CD.pin_code= 500081; strcpy(test_CD.vaccine_type[0].vaccine_name,"covaxin"); test_CD.vaccine_type[0].price=1000; test_CD.vaccine_type[0].quantity=50;
	strcpy(test_CD.vaccine_type[1].vaccine_name,"covishield"); test_CD.vaccine_type[0].price=1500; test_CD.vaccine_type[0].quantity=35;
	
	addNewCenter(test_CD);
	
	Center_data temp_c = findCenterById(test_CD.ID);
	
	if(temp_c.ID == test_CD.ID && temp_c.no_of_vaccine_types == test_CD.no_of_vaccine_types && temp_c.pin_code == test_CD.pin_code){
		printf("Added new center \n");
	}
	else{
		printf("Error in adding new center \n");
	}
}





void EnlistSortedCenters(int sort_key){
	Center_data temp;
	
	//printf("Enter the field you'd like the centers to be sorted by");
	//printf("1-ID \n 2-Pin_code \n 3-District-wise");
	//scanf("%d", &sort_key);
	
	if(sort_key == 1){
		for(int i=0;i<c_count-1; i++){
			for(int j=0; j<c_count-i-1; j++){
				if(CD[j].ID> CD[j+1].ID){
					temp=CD[j];
					CD[j]=CD[j+1];
					CD[j+1]=temp;
				}
			}
		}
	}
	else if(sort_key == 2){
		for(int i=0;i<c_count-1; i++){
			for(int j=0; j<c_count-i-1; j++){
				if(CD[j].pin_code> CD[j+1].pin_code){
					temp=CD[j];
					CD[j]=CD[j+1];
					CD[j+1]=temp;
				}
			}
		}	
	}
	else if (sort_key == 3){
		for(int i=0;i<c_count-1; i++){
			for(int j=0; j<c_count-i-1; j++){
				if(strcmp(CD[j].district, CD[j+1].district)<0){
					temp=CD[j];
					CD[j]=CD[j+1];
					CD[j+1]=temp;
				}
			}
		}
	} else {
		for(int i=0;i<c_count-1; i++){
			for(int j=0; j<c_count-i-1; j++){
				char key1[100];
				char key2[100];
				sprintf(key1, "%d-%d-%s", CD[j].ID, CD[j].pin_code, CD[j].district);
				sprintf(key2, "%d-%d-%s", CD[j+1].ID, CD[j+1].pin_code, CD[j+1].district);

				if(strcmp(key1, key2)<0){
					temp=CD[j];
					CD[j]=CD[j+1];
					CD[j+1]=temp;
				}
			}
		}
	}
	
	for(int m=0; m<c_count; m++){
		printf("%s %s ", CD[m].address, CD[m].district);
		printf("%d %c ", CD[m].pin_code, CD[m].center_type);
		for(int j=0; j<CD[m].no_of_vaccine_types; j++){
			printf("%s %d %d ", CD[m].vaccine_type[j].vaccine_name, CD[m].vaccine_type[j].price, CD[m].vaccine_type[j].quantity);
		}
		printf("\n");
	}
}

int getCenter(int sort_key, char param[10]){
	int pin=0, id=0;
	char dist[25], c_type, v_type[10];
	
	//printf("Enter the field you'd like the search the centers by");
	//printf("1-ID \n 2-District-wise \n 3-Pin_code \n 4-center type \n 5-vaccine type");
	//scanf("%d", &sort_key);
	
	
	if(sort_key == 1){
		//printf("Enter ID");
		//scanf("%d", &id);
		id = atoi(param);
		
		for(int i=0; i<c_count; i++){
			if(CD[i].ID == id){
				printf("%s %s ", CD[i].address, CD[i].district);
				printf("%d %c ", CD[i].pin_code, CD[i].center_type);
				for(int j=0; j<CD[i].no_of_vaccine_types; j++){
					printf("%s %d %d", CD[i].vaccine_type[i].vaccine_name, CD[i].vaccine_type[j].price, CD[i].vaccine_type[j].quantity);
				}
				printf("\n");
			}
		}
	}
	else if(sort_key == 2){
		/*printf("Enter district");
		scanf("%s", &dist);*/
		strcpy(dist, param);
		
		for(int i=0; i<c_count; i++){
			if(strcmp(CD[i].district, dist)==0){
				printf("%s %s ", CD[i].address, CD[i].district);
				printf("%d %c ", CD[i].pin_code, CD[i].center_type);
				for(int j=0; j<CD[i].no_of_vaccine_types; j++){
					printf("%s %d %d", CD[i].vaccine_type[i].vaccine_name, CD[i].vaccine_type[j].price, CD[i].vaccine_type[j].quantity);
				}
				printf("\n");
			}
		}
	}
	else if(sort_key == 3){
		/*printf("Enter pin_code");
		scanf("%d", &pin);*/
		
		pin = atoi(param);
		for(int i=0; i<c_count; i++){
			if(CD[i].pin_code == pin){
				printf("%s %s ", CD[i].address, CD[i].district);
				printf("%d %c ", CD[i].pin_code, CD[i].center_type);
				for(int j=0; j<CD[i].no_of_vaccine_types; j++){
					printf("%s %d %d", CD[i].vaccine_type[i].vaccine_name, CD[i].vaccine_type[j].price, CD[i].vaccine_type[j].quantity);
				}
				printf("\n");
			}
		}
	}
	else if(sort_key == 4){
		/*printf("Enter center type");
		scanf("%c", &c_type);*/
		
		c_type= param[0];
		
		for(int i=0; i<c_count; i++){
			printf("%s %s ", CD[i].address, CD[i].district);
			printf("%d %c ", CD[i].pin_code, CD[i].center_type);
			for(int j=0; j<CD[i].no_of_vaccine_types; j++){
				printf("%s %d %d", CD[i].vaccine_type[i].vaccine_name, CD[i].vaccine_type[j].price, CD[i].vaccine_type[j].quantity);
			}
		}
	}
	else if(sort_key == 5){
		/*printf("Enter vaccine type");
		scanf("%s", &v_type);*/
		
		strcpy(v_type, param);
		for(int i=0; i<c_count; i++){
			for(int k=0; k<CD[i].no_of_vaccine_types; k++){
				if(strcmp(CD[i].vaccine_type[k].vaccine_name,  v_type)==0){
					printf("%s %s ", CD[i].address, CD[i].district);
					printf("%d %c ", CD[i].pin_code, CD[i].center_type);
					for(int j=0; j<CD[i].no_of_vaccine_types; j++){
						printf("%s %d %d", CD[i].vaccine_type[j].vaccine_name, CD[i].vaccine_type[j].price, CD[i].vaccine_type[j].quantity);
					}
					printf("\n");
				}
			}
		}//not so sure
	}
}

void BookAppointment(int ID, int c_id, char* vac_type){
	//getting current time
	int year, day, month, flag=0, flag1=0, index_req=0;
	time_t now;   // not a primitive datatype
    time(&now);
    struct tm *local = localtime(&now); 
    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;
    
    Center_data take_center_info;
    Beneficiary_data take_beneficiary_info;
    
    
	//int flag = 0;
	/*printf("Enter your ID");
	scanf("%d", &ID);*/
	
	for(int i=0; i<a_count && flag==0; i++){
		if(ID == appointments[i].b_id && appointments[i].app_date.dd == day && appointments[i].app_date.mm == month && appointments[i].app_date.yy == year){
			flag = 1;
		}
	}
	
	for(int i=0; i<b_count && flag==0; i++){
		if(BD[i].ID == ID && BD[i].no_of_doses == 2){
			flag = 1;
		}
	}
	
	
	if(flag == 0){
		
		
		appointments[a_count].b_id = ID;
		//printf("Enter your ID, the center ID and vaccine type");
		//scanf("%d %d ", &appointments[a_count].c_id, &appointments[a_count].vac_type.price, &appointments[a_count].vac_type.quantity);
		//scanf("%c %d", &appointments[a_count].vac_type.vaccine_name, &appointments[a_count].dose);
		//scanf("%d %d %d", &appointments[a_count].app_date.dd, &appointments[a_count].app_date.mm, &appointments[a_count].app_date.yy);
		
		take_center_info = findCenterById(c_id);
		take_beneficiary_info = findBeneficiaryById(ID);
		
		for(int i=0; i<take_center_info.no_of_vaccine_types && flag1==0; i++){
			if(strcmp(take_center_info.vaccine_type[i].vaccine_name, vac_type)==0){
				index_req=i;
				flag1=1;
			}
		}
		
		appointments[a_count].c_id=c_id; strcpy(appointments[a_count].vac_type.vaccine_name, vac_type);
		appointments[a_count].vac_type.price = take_center_info.vaccine_type[index_req].price;
		appointments[a_count].dose = take_beneficiary_info.no_of_doses+1;
		appointments[a_count].app_date.dd = day; appointments[a_count].app_date.mm = month; appointments[a_count].app_date.yy = year;
		
		for(int i=0; i<b_count && flag==0; i++){
			if(BD[i].ID == ID){
				BD[i].no_of_doses++;
				flag=1;
			}
		}
		
		a_count++;
	
		printf("Appointment has successfully been booked \n");
	}
	else{
		printf("Cannot book appointment \n");
	}
}// not suree

void CancelAppointment(int search_b_id){
	int status=0;
	/*printf("Enter your ID");
	scanf("%d", &search_b_id);*/
	
	//a_count--;	
	for(int i=0; i<a_count; i++){
		if(search_b_id == appointments[i].b_id && status==0){
			status = 1;
		}
		else if(status==1){
			appointments[i-1] = appointments[i];
		}
	}
	
	if(status==1){
		a_count--;
		printf("Appointment successfully cancelled \n");
	}
	else{
		printf("No appointment found for the beneficiary \n");
	}

}//not sure...

void removeBeneficiary(int search_b_id){
	int status=0;
	/*printf("Enter your ID");
	scanf("%d", &search_b_id);*/
	
	
	for(int i=0; i<b_count; i++){
		if(search_b_id == BD[i].ID && status==0){
			status = 1;
		}
		else if(status==1){
			BD[i-1] = BD[i];
		}
	}
	
	if(status ==1){
		b_count--;
		printf("Beneficiary successfully removed \n");
	}
	else{
		printf("Beneficiary not found \n");
	}
}

void removeCentre(int search_c_id){
	int status=0;
	/*printf("Enter your ID");
	scanf("%d", &search_c_id);*/
	
	for(int i=0; i<c_count; i++){
		if(search_c_id == CD[i].ID && status==0){
			status = 1;
		}
		else if(status==1){
			CD[i-1] = CD[i];
		}
	}
	
	if(status==1){
		c_count--;
		printf("Center successfully removed \n");
	}
	else{
		printf("Center not found");
	}
}

void UpdateBeneficiaryInfo(Beneficiary_data update_BD){
	int found=0;
	
	for(int i=0; i<b_count && found ==0; i++){
		if(BD[i].ID == update_BD.ID){
			if(BD[i].dob.dd != update_BD.dob.dd){
				BD[i].dob.dd = update_BD.dob.dd;
			}
			else if(BD[i].dob.mm != update_BD.dob.mm){
				BD[i].dob.mm = update_BD.dob.mm;
			}
			else if(BD[i].dob.yy != update_BD.dob.yy){
				BD[i].dob.yy = update_BD.dob.yy;
			}
			else if(BD[i].gender != update_BD.gender){
				BD[i].gender != update_BD.gender;
			}
			else if(strcmp(BD[i].nm.fn, update_BD.nm.fn)!=0){
				strcpy(BD[i].nm.fn, update_BD.nm.fn);
			}
			else if(strcmp(BD[i].nm.ln, update_BD.nm.ln)!=0){
				strcpy(BD[i].nm.ln, update_BD.nm.ln);
			}
			else if(BD[i].no_of_doses != update_BD.no_of_doses){
				BD[i].no_of_doses = update_BD.no_of_doses;
			}
			printf("Beneficiary information has been successfully updated\n");
			found =1;
		}
	}
	
	/*printf("Enter your ID");
	scanf("%d", &search_b_id);
	
	printf("Enter the fields you wish to update");
	printf("1-Full name \n 2-Gender \n 3-DOB \n 4- number of doses taken");
	scanf("%d", &search_key);*/
	
	/*for(i=0; i<b_count; i++){
		if(BD[i].ID == search_b_id){
			if(search_key == 1){
				printf("Enter new first name");
				scanf("%s", &BD[i].nm.fn);
				
				printf("Enter new last name");
				scanf("%s", &BD[i].nm.ln);
			}
			else if(search_key == 2){
				printf("Enter updated value of gender");
				scanf("%c", &BD[i].gender);
			}
			else if(search_key == 3){
				printf("Enter new day, month and year respectively");
				scanf("%d %d %d", &BD[i].dob.dd, &BD[i].dob.mm, &BD[i].dob.yy);
			}
			else if(search_key == 4){
				printf("enter updated value of no.of doses taken");
				scanf("%d", &BD[i].no_of_doses);
			}
		}
	}*/
}

void UpdateCenterInfo(Center_data update_CD){
	int found=0;
	
	for(int i=0; i<c_count && found ==0; i++){
		if(CD[i].ID == update_CD.ID){
			if(CD[i].pin_code != update_CD.pin_code){
				CD[i].pin_code = update_CD.pin_code;
			}
			else if(CD[i].no_of_vaccine_types != update_CD.no_of_vaccine_types){
				CD[i].no_of_vaccine_types != update_CD.no_of_vaccine_types;
			}
			else if(CD[i].center_type != update_CD.center_type){
				CD[i].center_type = update_CD.center_type;
			}
			else if(strcmp(CD[i].address, update_CD.address)!=0){
				strcpy(CD[i].address, update_CD.address);
			}
			else if(strcmp(CD[i].district, update_CD.district)!=0){
				strcpy(CD[i].district, update_CD.district);
			}
			for(int j=0; j<CD[i].no_of_vaccine_types; j++){
				if(strcmp(CD[i].vaccine_type[j].vaccine_name, update_CD.vaccine_type[j].vaccine_name) !=0){
					strcpy(CD[i].vaccine_type[j].vaccine_name, update_CD.vaccine_type[j].vaccine_name);
				}
				else if(CD[i].vaccine_type[j].price != update_CD.vaccine_type[j].price){
					CD[i].vaccine_type[j].price = update_CD.vaccine_type[j].price;
				}
				else if(CD[i].vaccine_type[j].quantity != update_CD.vaccine_type[j].quantity){
					CD[i].vaccine_type[j].quantity = update_CD.vaccine_type[j].quantity;
				}
			}
			printf("Center information has been successfully updated\n");
			found =1;
		}
	}
	
	/*printf("Enter your ID");
	scanf("%d", &search_c_id);
	
	printf("Enter the fields you wish to update");
	printf("1-Address \n 2-District \n 3-PIN code \n 4- center type \n vaccine types");
	scanf("%d", &search_key);
	
	for(i=0; i<c_count; i++){
		if(CD[i].ID == search_c_id){
			if(search_key == 1){
				printf("Enter new address");
				scanf("%s", &CD[i].address);
			}
			else if(search_key == 2){
				printf("Enter updated district");
				scanf("%s", &CD[i].district);
			}
			else if(search_key == 3){
				printf("Enter PIN code");
				scanf("%d", &CD[i].pin_code);
			}
			else if(search_key == 4){
				printf("enter updated value of center type");
				scanf("%c", &CD[i].center_type);
			}
			else if(search_key == 5){
				for(int j=0; j<CD[i].no_of_vaccine_types; j++){
					printf("Enter the updated vaccine type, it's respected quantity and the price");
					scanf("%s %d %d", &CD[i].vaccine_type[j].vaccine_name, &CD[i].vaccine_type[j].quantity, &CD[i].vaccine_type[j].price);
				}
			}
		}
	}*/
}

void MaxIncomeCentre(){
	int max_income=0, center_max_income=0, center_income[c_count][2], found =0;	 //0th column=>center; 1st column=>total income
	
	//creating 2d array
	int count=0;
	for(int i=0; i<a_count; i++){
		found = 0; int j=0;
		for(j=0; j<count && found ==0; j++){
			if(appointments[i].c_id == center_income[j][0]){
				center_income[j][1] += appointments[i].vac_type.price;
				printf("price in on appointment = %d, total price = %d  found = 1\n", appointments[i].vac_type.price, center_income[j][1]);
				found =1;
			}
		}
		if(found ==0){
			center_income[count][0] = appointments[i].c_id;
			center_income[count][1] += appointments[i].vac_type.price;
			printf("price in on appointment = %d, total price = %d  found = 0\n", appointments[i].vac_type.price, center_income[count][1]);
			count++;
		}
	}
	
	//finding max value of 2nd column in the 2d array
	for(int i=0; i<count; i++){
		if(center_income[i][1] > max_income){
			max_income = center_income[i][1];
			center_max_income = center_income[i][0];
			printf("center_max_income = %d, max_income = %d \n", center_max_income, max_income);
		}
	}
	
	for(int i=0; i<c_count; i++){
		if(center_max_income == CD[i].ID){
			printf("%s %s ", CD[i].address, CD[i].district);
			printf("%d %c ", CD[i].pin_code, CD[i].center_type);
			for(int j=0; j<CD[i].no_of_vaccine_types; j++){
				printf("%s %d %d", CD[i].vaccine_type[j].vaccine_name, CD[i].vaccine_type[j].price, CD[i].vaccine_type[j].quantity);
			}
			printf("\n");
		}
	}
}

void VaccineAvailabilityReport(){
	int count=0,vaccine_available[c_count][7];
	Center_data temp;
	// sorting acc to dirstricts
	for(int i=0;i<c_count-1; i++){
		for(int j=0; j<c_count-i-1; j++){
			if(strcmp(CD[j].district, CD[j+1].district)<0){
				temp=CD[j];
				CD[j]=CD[j+1];
				CD[j+1]=temp;
			}
		}
	}
	for(int i=0; i<c_count; i++) {
		for(int j=0; j<7; j++) {
			vaccine_available[i][j] = 0;
		}
	}
	//checking the no of times appointment has been made in each center
	/*
	1-covaxin
	2-covishield
	3-sputnik
	4-zydus
	5-pfizer
	6-moderna
	*/
	//creating a 2D array that stores the count of all vaccines used
	for(int i=0; i<a_count; i++){
		int found = 0;
		for(int j=0; j<count && found ==0; j++){
			//search id center has been entered in the array before
			if(appointments[i].c_id == vaccine_available[j][0]){
				if(strcmp(appointments[i].vac_type.vaccine_name, "covaxin")==0){
					vaccine_available[j][1]++;
				}
				else if(strcmp(appointments[i].vac_type.vaccine_name, "covishield")==0){
					vaccine_available[j][2]++;
				}
				else if(strcmp(appointments[i].vac_type.vaccine_name, "sputnik")==0){
					vaccine_available[j][3]++;
				}
				else if(strcmp(appointments[i].vac_type.vaccine_name, "zydus")==0){
					vaccine_available[j][4]++;
				}
				else if(strcmp(appointments[i].vac_type.vaccine_name, "pfizer")==0){
					vaccine_available[j][5]++;
				}
				else if(strcmp(appointments[i].vac_type.vaccine_name, "moderna")==0){
					vaccine_available[j][6]++;
				}
				found = 1;
			}
			
		}
		
		if(found == 0){
				vaccine_available[count][0] = appointments[i].c_id;
				
				if(strcmp(appointments[i].vac_type.vaccine_name, "covaxin")==0){
					vaccine_available[count][1]++;
				}
				else if(strcmp(appointments[i].vac_type.vaccine_name, "covishield")==0){
					vaccine_available[count][2]++;
				}
				else if(strcmp(appointments[i].vac_type.vaccine_name, "sputnik")==0){
					vaccine_available[count][3]++;
				}
				else if(strcmp(appointments[i].vac_type.vaccine_name, "zydus")==0){
					vaccine_available[count][4]++;
				}
				else if(strcmp(appointments[i].vac_type.vaccine_name, "pfizer")==0){
					vaccine_available[count][5]++;
				}
				else if(strcmp(appointments[i].vac_type.vaccine_name, "moderna")==0){
					vaccine_available[count][6]++;
				}
				count++;
			}
	}
	
	//subtracting the vaccine availability array with the quantity of each of the vaccines in each of the centers
	for(int i=0; i<c_count; i++){		//going through center array of structures
		int found = 0;
		for(int j=0; j<count && found ==0; j++){	//going through vaccine availability arrya
			if(CD[i].ID == vaccine_available[j][0]){
				for(int k=0; k<CD[i].no_of_vaccine_types; k++){		//going through each of the vaccine types
					if(strcmp(CD[i].vaccine_type[k].vaccine_name, "covaxin")==0){
						vaccine_available[j][1] = CD[i].vaccine_type[k].quantity-vaccine_available[j][1];
					}
					else if(strcmp(CD[i].vaccine_type[k].vaccine_name, "covishield")==0){
						vaccine_available[j][2] = CD[i].vaccine_type[k].quantity-vaccine_available[j][2];
					}
					else if(strcmp(CD[i].vaccine_type[k].vaccine_name, "sputnik")==0){
						vaccine_available[j][3] = CD[i].vaccine_type[k].quantity-vaccine_available[j][3];
					}
					else if(strcmp(CD[i].vaccine_type[k].vaccine_name, "zydus")==0){
						vaccine_available[j][4] = CD[i].vaccine_type[k].quantity-vaccine_available[j][4];
					}
					else if(strcmp(CD[i].vaccine_type[k].vaccine_name, "pfizer")==0){
						vaccine_available[j][5] = CD[i].vaccine_type[k].quantity-vaccine_available[j][5];
					}
					else if(strcmp(CD[i].vaccine_type[k].vaccine_name, "moderna")==0){
						vaccine_available[j][6] = CD[i].vaccine_type[k].quantity-vaccine_available[j][6];
					}
				}
				found =1;
			}
		}
		if(found ==0){
			for(int k=0; k<CD[i].no_of_vaccine_types; k++){
				vaccine_available[count][0] = CD[i].ID;
				if(strcmp(CD[i].vaccine_type[k].vaccine_name, "covaxin")==0){
						vaccine_available[count][1] = CD[i].vaccine_type[k].quantity;
					}
					else if(strcmp(CD[i].vaccine_type[k].vaccine_name, "covishield")==0){
						vaccine_available[count][2] = CD[i].vaccine_type[k].quantity;
					}
					else if(strcmp(CD[i].vaccine_type[k].vaccine_name, "sputnik")==0){
						vaccine_available[count][3] = CD[i].vaccine_type[k].quantity;
					}
					else if(strcmp(CD[i].vaccine_type[k].vaccine_name, "zydus")==0){
						vaccine_available[count][4] = CD[i].vaccine_type[k].quantity;
					}
					else if(strcmp(CD[i].vaccine_type[k].vaccine_name, "pfizer")==0){
						vaccine_available[count][5] = CD[i].vaccine_type[k].quantity;
					}
					else if(strcmp(CD[i].vaccine_type[k].vaccine_name, "moderna")==0){
						vaccine_available[count][6] = CD[i].vaccine_type[k].quantity;
					}
			}
			count++;
		}
	}
	
	printf("Center ID \t covaxin \t covishield \t sputnik \t zydus \t pfizer \t moderna \n");
	for(int i=0; i<c_count; i++){
		for(int j=0; j<6; j++){
			printf("%d \t ", vaccine_available[i][j]);
		}
		printf("\n");
	}
}

void DistrictReport(){
	// sorting acc to dirstricts
	Center_data temp;
	int k=0, count=0;
	
//	for(int i=0; i<a_count; i++){
//		printf("%d %d %d %d \n", appointments[i].c_id, appointments[i].app_date.dd, appointments[i].app_date.mm, appointments[i].app_date.yy);
//	}

	
	for(int i=0;i<c_count-1; i++){
		for(int j=0; j<c_count-i-1; j++){
			if(strcmp(CD[j].district, CD[j+1].district)<0){
				temp=CD[j];
				CD[j]=CD[j+1];
				CD[j+1]=temp;
			}
		}
	}
	
	
	//now will have too loop agn
	for(int i=0; i<c_count; i++){
		if(i > 0 && strcmp(CD[i-1].district, CD[i].district) != 0) {
			
			printf("District = %s, Vaccines booked = %d\n", CD[i-1].district, count);
			count = 0;
		}
			k = 0;
			while(k<a_count) {
				if(CD[i].ID == appointments[k].c_id){
					count++;
				}
				k++;
			}
	}
	printf("District = %s, Vaccines booked = %d\n", CD[c_count-1].district, count);
}

int return_index(int bene_id){
	int year;
	time_t now;   // not a primitive datatype
    time(&now);
    struct tm *local = localtime(&now); 
    year = local->tm_year + 1900;
    
	int flag=0, birth_yr=0, retval=0;
	for(int i=0; i<b_count && flag==0; i++){
		if(BD[i].ID == bene_id){
			birth_yr = BD[i].dob.yy;
			flag = 1;
			if(year-birth_yr>60){
				retval = i;
				flag = 1;
			}
		}
	}

	return retval;
}

void SeniorCitizenIntersection(){
	int List1[4], List2[3];
	int L1_index=0, L2_index=0, center1=0, center2=0;
	
	//creating List1 & List2
	for(int i=0; i<a_count; i++){
		int BD_index = return_index(appointments[i].b_id);
		if(appointments[i].dose == 1 && BD_index != 0){
			List1[L1_index] = BD[BD_index].ID;// List1[L1_index]. = BD[BD_index].ID;
			L1_index++;
		}
		if(appointments[i].dose == 2 && BD_index != 0){
			List2[L2_index] = BD[BD_index].ID;
			L2_index++;
		}
	}
	
	//int j=0;
	//printf("a_count:%d\n", a_count);
	for(int i=0; i<L2_index; i++){
		int found = 0;
		for(int j=0; j<a_count; j++){
			//printf("-------a_bid: %d, l_bid:%d\n", appointments[j].b_id,  List2[i]);
			if(appointments[j].b_id == List2[i]){
				if(found == 0){
					center1 = appointments[j].c_id;
					found=1;
				}
				else{
					center2 = appointments[j].c_id;
				}
				found = 1;
			}
		}
		if(center1 == center2){
			printf("Beneficiary ID=%d, Center ID= %d\n", List2[i], center1);
		}
	}
}

main(){
	FILE *b_data_file = fopen("Beneficiary_Data.txt", "r");
	FILE *c_data_file = fopen("Center_Data.txt", "r");
	char line[1000];
	
	//getting beneficiary data from file
    while (fgets(line, sizeof(line), b_data_file)) {
    	sscanf(line, "%d %s %s %c %d %d %d %d", 
				&BD[b_count].ID, &BD[b_count].nm.fn, &BD[b_count].nm.ln,
				&BD[b_count].gender, &BD[b_count].dob.dd, &BD[b_count].dob.mm, &BD[b_count].dob.yy,
				&BD[b_count].no_of_doses);

        
        //printf("%d %s %s \n", BD[b_count].ID, BD[b_count].nm.fn,  BD[b_count].nm.ln);
        
        b_count++;
    }
    //getting center data from file
    while (fgets(line, sizeof(line), c_data_file)) {
    	char vtypes[500];
    	sscanf(line, "%d %s %s %d %c %d %s", &CD[c_count].ID, CD[c_count].address, CD[c_count].district,
				 &CD[c_count].pin_code, &CD[c_count].center_type, &CD[c_count].no_of_vaccine_types, vtypes);
				
		char * token = strtok(vtypes, ";");
		int typecount = 0;
		// loop through the string to extract all other tokens
	   while( token != NULL ) {
	   		char tmp[10];
	   		sscanf(token, "%[^_]_%[^_]_%d", CD[c_count].vaccine_type[typecount].vaccine_name, tmp, &CD[c_count].vaccine_type[typecount].quantity);
	   		CD[c_count].vaccine_type[typecount].price = atoi(tmp);
	   		typecount++;
	      	token = strtok(NULL, ";");
	   }
    			
//		printf("%s %s \n", CD[c_count].address, CD[c_count].district);
//		printf("%d %c %s %d %d\n", CD[c_count].pin_code, CD[c_count].center_type, CD[c_count].vaccine_type[0].vaccine_name, CD[c_count].vaccine_type[0].price, CD[c_count].vaccine_type[0].quantity);
        
        c_count++;
    }
	
	
	//test case 1
	printf("----------------------------\n\n");
	printf("Executing AddNewBeneficiary\n");
	testAddNewBeneficiary();
	
	//test csae 2
	printf("----------------------------\n\n");
	printf("Executing testAddNewCenter\n");
	testAddNewCenter();	
	
	//test case 3
	printf("----------------------------\n\n");
	printf("Executing EnlistSortedCenters \n");
	EnlistSortedCenters(2);

	
	//test case 4
	printf("----------------------------\n\n");
	printf("Executing getCenter...\n");
	getCenter(5, "covaxin");
	
	//test case 5
	printf("----------------------------\n\n");
	printf("Booking 3 appointments... \n");
	BookAppointment(3, 1, "covaxin");
	BookAppointment(1, 2, "covaxin");
	BookAppointment(2, 1, "covishield");
	
	printf("----------------------------\n\n");
	printf("Cancelling Appointment for Beneficiary-id: 1\n");
	CancelAppointment(1);
	
	printf("----------------------------\n\n");
	printf("Removing Beneficiary-id: 1\n");
	removeBeneficiary(1);
	
	printf("----------------------------\n\n");
	printf("Removing Center-id: 1\n");
	removeCentre(1);
	
	printf("----------------------------\n\n");
	printf("Updating Beneficiary-id: 3. Updated FirstName, LastName, DOB\n");
	Beneficiary_data update_BD;
	update_BD.dob.dd = 9; update_BD.dob.mm= 9; update_BD.dob.yy = 1999; update_BD.gender = 'm'; update_BD.ID = 00003; strcpy(update_BD.nm.fn, "Raksha");
	strcpy(update_BD.nm.ln, "Bandhan"); update_BD.no_of_doses = 1;
	
	UpdateBeneficiaryInfo(update_BD);
	
	printf("----------------------------\n\n");
	printf("Updating Center-id: 4. Updated Address, District, Type, Number of Vaccines, Pincode, Vaccine Price & Vaccine Quantity\n");
	Center_data update_CD;
	strcpy(update_CD.address , "road_no1234,sriram_nagar"); update_CD.center_type= 'p'; strcpy(update_CD.district, "Medak"); update_CD.ID=4; update_CD.no_of_vaccine_types=1;
	update_CD.pin_code=500084; strcpy(update_CD.vaccine_type[0].vaccine_name, "moderna"); update_CD.vaccine_type[0].price=700; update_CD.vaccine_type[0].quantity=75;
	
	UpdateCenterInfo(update_CD);
	
	printf("----------------------------\n\n");
	printf("Finding center with Maximum Income..\n");
	MaxIncomeCentre();

printf("----------------------------\n\n");
	printf("VaccineAvailabilityReport..\n");	
	VaccineAvailabilityReport();
	
	printf("----------------------------\n\n");
	printf("DistrictReport..\n");	
	DistrictReport();
	
	printf("----------------------------\n\n");
	BookAppointment(4, 1, "covaxin");
	BookAppointment(4, 1, "covaxin");
	
	BookAppointment(5, 2, "covaxin");
	BookAppointment(5, 2, "covaxin");
	
	BookAppointment(6, 1, "covishield");
	BookAppointment(6, 1, "covishield");
	
	printf("SeniorCitizenIntersection..\n");
	SeniorCitizenIntersection();
}

