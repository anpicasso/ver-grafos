#include <iostream>
#include <vector>
#include <windows.h>
#include <dirent.h>

using namespace std;

vector <string> listar() {
	vector <string> ans;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("Matrices")) != NULL) {
		while ((ent = readdir (dir)) != NULL) {
			//printf ("%s\n", ent->d_name);
			int l = strlen(ent->d_name);
			if (l <= 3) continue;
			
			string name = "";
			for (int i = 0; i < l; i++) {
				name += ent->d_name[i];
			}
			if (name[l-3] == 'm' && name[l-2] == 'p' && name[l-1] == '4') {
				ans.push_back(name);
			}
		}
		closedir (dir);
	} else {
		perror ("");
	}
	return ans;
}

int main(){
	vector <string> v = listar();
	
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	
	cout<<'á'<<'é'<<'í'<<'ó'<<'ú'<<endl;
}