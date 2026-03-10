//Ứng dụng quản lý ngân hàng

#include <iostream>
#include <string>
using namespace std;

//struct của Tài khoản ngân hàng
struct Account{
	string ID;
	string Name;
	int balance;
	
	Account(){
		ID = Name = "";
		balance = 0;
	}	
};

Account ds[50];
int n=0;

//hàm check lựa chọn từ menu
bool CheckLuaChonDau(string &ch){
	if (ch.size()==0){
		return false;
	}
	for (char c : ch){
		if (!isdigit(c)){
			return false;
		}
	}
	return true;
}

//hàm tự động tạo ID tài khoản
string AutoGenerateAcc(int &so){
	int sotk = so+1;
	if (sotk<10){
		return "ACC00" + to_string(sotk);
	}
	else{
		return "ACC0" + to_string(sotk);
	}	
}

//hàm kiểm tra tính hợp lệ của tên
bool CheckTen(string &name){
	if (name.size()>50){
		return false;
	}
	return true;
}

//hàm tạo tài khoản mới
void taoTK(){
	cout << "==============================================\n";
	cout << "Ban muon tao bao nhieu tai khoan?\n";
	int choice;
	while(true){
		cout << "Lua chon: ";
		cin>>choice;
		
		if (cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Sai dinh dang, nhap lai!\n";
			cout << "------------------------------------------\n";
			continue;
		}
		break;
	}
	
	cin.ignore(1000, '\n');
	
	if (n+choice>50){
		cout << "Chi co the tao toi da 50 TK!\n";
		return;
	}
	int preN=n;
	n+=choice;
	
	for (int i=preN; i<n; i++){
		cout << "ID tai khoan so " << i+1 << " cua ban la: " << AutoGenerateAcc(i) << "\n";
		ds[i].ID=AutoGenerateAcc(i);
		
		while (true){
			cout << "Ho va Ten cua ban? (toi da 50 ki tu): ";
			getline(cin, ds[i].Name);
			
			if (CheckTen(ds[i].Name)){
				break;
			}
			cout << "Khong duoc vuot qua 50 ki tu, nhap lai!\n";
			cout << "------------------------------------------\n";
		}
		cout << "----------------------------\n";
	}
	
}

//hàm thống kê tài khoản đã tạo
void thongkeTK(){
	cout << "==============================================\n";
	if (n==0){
		cout << "Chua tao tai khoan nao, vui long tao it nhat 1 tai khoan de tiep tuc\n";
		return;
	}
	for (int i=0; i<n; i++){
		cout << "STT: " << i+1 << "\n";
		cout << "Tai khoan co ID: " << ds[i].ID << "\n";
		cout << "Ho Ten chu tai khoan: " << ds[i].Name << "\n";
		cout << "So du tai khoan: " << ds[i].balance << " VND\n";
		cout << "------------------------------------------\n";
	}
}

//hàm check tính hợp lệ của tiền nạp vào
bool checkTienNap(int &tien){
	if (cin.fail()){
		cin.clear();
		cin.ignore(1000, '\n');
		return false;
	}
	if (tien < 2000){
		return false;
	}
	return true;
}

//hàm nạp tiền vào tài khoản
void naptien(){
	cout << "==============================================\n";
	if (n==0){
		cout << "Chua tao tai khoan nao, vui long tao it nhat 1 tai khoan de tiep tuc\n";
		return;
	}
	cin.ignore(1000, '\n');
	string id;
	cout << "Nhap ID tai khoan can nap tien vao: ";
	getline(cin, id);
	
	int tiennapvao;
	
	for (int i=0; i<n; i++){
		if (id == ds[i].ID){
			while(true){
				cout << "Ban muon nap bao nhieu tien? (phai lon hon 2000 VND)\n";
				cout << "Lua chon: ";
				cin >> tiennapvao;
				
				if (cin.fail()){
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Sai dinh dang, nhap lai!\n";
					cout << "------------------------------------------\n";
					continue;
				}
				if (tiennapvao<0){
					cout << "Khong the nap so tien am, nhap lai!\n";
					cout << "------------------------------------------\n";
					continue;
				}
				if (tiennapvao<2000){
					cout << "So tien be hon 2000 VND, nhap lai!\n";
					cout << "------------------------------------------\n";
					continue;
				}
				
				ds[i].balance+=tiennapvao;
				cout << "So du hien tai cua ban: " << ds[i].balance << "\n";
				cout << "------------------------------------------\n";
				return;
				
			}
		}
	}
	cout << "Khong tim thay tai khoan mong muon :(\n";
}

//hàm rút tiền khỏi tài khoản
void ruttien(){
	cout << "==============================================\n";
	if (n==0){
		cout << "Chua tao tai khoan nao, vui long tao it nhat 1 tai khoan de tiep tuc\n";
		return;
	}
	cin.ignore(1000, '\n');
	string id;
	cout << "Nhap ID tai khoan can rut tien ra: ";
	getline(cin, id);
	
	int tienrutra;
	
	for (int i=0; i<n; i++){
		if (id == ds[i].ID){
			if (ds[i].balance==0){
				cout << "So du tai khoan khong du, vui long nap them tien truoc khi co the rut!\n";
				return;
			}
			while(true){
				cout << "Ban muon rut bao nhieu tien?\n";
				cout << "Lua chon: ";
				cin >> tienrutra;
				
				if (cin.fail()){
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Sai dinh dang, nhap lai!\n";
					cout << "------------------------------------------\n";
					continue;
				}
				
				if (tienrutra<0){
					cout << "Khong the rut so tien am, nhap lai!\n";
					cout << "------------------------------------------\n";
					continue;
				}
				
				if (tienrutra>ds[i].balance){
					cout << "Khong the rut qua so du tai khoan, nhap lai!\n";
					cout << "------------------------------------------\n";
					continue;
				}
				
				ds[i].balance-=tienrutra;
				cout << "So du hien tai cua ban: " << ds[i].balance << "\n";
				cout << "------------------------------------------\n";
				return;
				
			}
		}
	}
	cout << "Khong tim thay tai khoan mong muon :(\n";
}

//hàm tìm tài khoản theo ID
void timTK(){
	cout << "==============================================\n";
	if (n==0){
		cout << "Chua tao tai khoan nao, vui long tao it nhat 1 tai khoan de tiep tuc\n";
		return;
	}
	
	cin.ignore(1000, '\n');
	string id;
	cout << "Nhap ID tai khoan can tim: ";
	getline(cin, id);
	
	for (int i=0; i<n; i++){
		if (id == ds[i].ID){
			cout << "Tai khoan co ID: " << ds[i].ID << "\n";
			cout << "Ho Ten chu tai khoan: " << ds[i].Name << "\n";
			cout << "So du tai khoan: " << ds[i].balance << " VND\n";
			cout << "------------------------------------------\n";
			return;
		}
	}
	cout << "Khong tim thay tai khoan mong muon :(\n";
}

//hàm chuyển khoản
void chuyenkhoan(){
	cout << "==============================================\n";
	if (n==0){
		cout << "Chua tao tai khoan nao, vui long tao it nhat 2 tai khoan de tiep tuc\n";
		return;
	}
	if (n==1){
		cout << "Hay tao them it nhat 1 tai khoan truoc khi co the chuyen khoan\n";
		return;
	}
	
	cout << "Hien gio ban dang co: " << n << " Tai khoan\n";
	for (int i=0; i<n; i++){
		cout << "ID: " << ds[i].ID << " || "; cout << "So du tai khoan: " << ds[i].balance << " VND\n";
	}
	
	cin.ignore(1000, '\n');
	
	string choice1;
	int index1;
	while (true){
		bool found = false;
		cout << "Ban muon lay tai khoan ID nao de chuyen tien?: ";
		getline(cin, choice1);
		for (int i=0; i<n; i++){
			if (choice1 == ds[i].ID){
				choice1 = ds[i].ID;
				index1 = i;
				if (ds[index1].balance==0){
					cout << "Lua chon khong hop le, so du tai khoan = 0 nen khong the chuyen tien\n";
					return;
				}
				cout << "Chon thanh cong!\n";
				found = true;
				break;
			}
		}
		if (found){
			break;
		}
		cout << "Khong tim thay ID tuong ung\n";
		continue;
	}
	
	string choice2;
	int index2;
	while (true){
		bool found = false;
		cout << "Ban muon lay tai khoan ID nao de nhan tien?: ";
		getline(cin, choice2);
		for (int i=0; i<n; i++){
			if (choice2 == ds[i].ID){
				choice2 = ds[i].ID;
				index2 = i;
				cout << "Chon thanh cong!\n";
				found = true;
				break;
			}
		}
		if (found){
			break;
		}
		cout << "Khong tim thay ID tuong ung\n";
		continue;
	}
	
	cout << "Lua chon cua ban: \n";
	cout << "Tai khoan chuyen tien: " << choice1 << "\n";
	cout << "Tai khoan nhan tien: " << choice2 << "\n";
	
	cout << "Ban muon chuyen bao nhieu tien?\n";
	int choiceCK;
	while (true){
		cout << "Lua chon: ";
		cin >> choiceCK;
		
		if (cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Lua chon khong hop le, nhap lai!\n";
			cout << "------------------------------------------\n";
			continue;
		}
		if (choiceCK <0){
			cout << "Khong the chuyen so tien am, nhap lai!\n";
			cout << "------------------------------------------\n";
			continue;
		}
		break;
	}
	if (choiceCK > ds[index1].balance){
		cout << "So tien muon chuyen qua lon!...\n";
		return;
	}
	ds[index1].balance-=choiceCK;
	ds[index2].balance+=choiceCK;
	
	cout << "So du sau khi chuyen khoan:\n";
	cout << "ID: " << choice1 << " || "; cout << "So du tai khoan: " << ds[index1].balance << " VND\n";
	cout << "ID: " << choice2 << " || "; cout << "So du tai khoan: " << ds[index2].balance << " VND\n";
	
}
int main(){
	while (true){
		cout << "\n=====================MENU=====================\n";
		cout << "||  1. Tao tai khoan ngan hang              ||\n";             
		cout << "||  2. Thong ke tai khoan cua ban           ||\n";
		cout << "||  3. Nap tien vao tai khoan               ||\n";
		cout << "||  4. Rut tien ra                          ||\n";
		cout << "||  5. Tim tai khoan theo ID                ||\n";
		cout << "||  6. Chuyen tien vao tai khoan khac       ||\n";
		cout << "||  0. Thoat app                            ||\n";
		cout << "==============================================\n";
		
		string choice;
		cout << "Lua chon: ";
		cin >> choice;	
		if (!CheckLuaChonDau(choice)){
			cout << "Sai dinh dang, nhap lai!\n";
			continue;
		}
		int finalchoice = stoi(choice);
		
		switch(finalchoice){
			case 1: taoTK(); break;
			case 2: thongkeTK(); break;
			case 3: naptien(); break;
			case 4: ruttien(); break;
			case 5: timTK(); break;
			case 6: chuyenkhoan(); break;
			case 0: return 0;
			default: cout << "Khong tim thay lua chon, nhap lai!\n";
		}
	}
	return 0;
}