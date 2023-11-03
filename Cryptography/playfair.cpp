#include <iostream>
#include <utility>
#include <unordered_map>

std::string get_key_string(std::string key){
	int x[26], i, idx, c=1;
	std::string ret;
	for (i = 0; i<=25; i++){
		x[i] = 0;
		key +=(char) (i+97);
	}
	std::cout << "Key matrix is:" << std::endl;
	for (i=0; i<key.size(); i++){
		if (key[i]=='j') continue;
		idx = key[i] - 97;
		if (!x[idx]){
			x[idx] = 1;
			ret += key[i];
			std::cout << key[i];
			if (c++%5 == 0) std::cout << std::endl;
		}
	}
	return ret;
}

auto make_matrix(std::string key_string){
	std::unordered_map<char, std::pair<int, int>> ret;
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++)
			ret[key_string[i*5 + j]] = std::make_pair(i, j);
	}
	return ret;
}

std::string encrypt(std::string key,std::string plain){
	int i, r1, r2, c1, c2;
	auto matrix = make_matrix(key);
	plain += 'a' * (plain.size()%2);
	std::string ret = plain;
	for (i = 0; i+1<plain.size(); i+=2){
		plain[i] -= 1*(plain[i]=='j');
		r1 = matrix[plain[i]].first;
		r2 = matrix[plain[i+1]].first;
		c1 = matrix[plain[i]].second;
		c2 = matrix[plain[i+1]].second;
		if (r1==r2){
			c1 = (c1+1)%5;
			c2 = (c2+1)%5;
			ret[i] = key[r1*5 +c1];
			ret[i+1] = key[r2*5 + c2];
		}
		else if (c1==c2){
			r1 = (r1+1)%5;
			r2 = (r2+1)%5;
			ret[i] = key[r1*5 +c1];
			ret[i+1] = key[r2*5 +c1];
		}
		else{
			ret[i] = key[r1*5 + c2];
			ret[i+1] = key[r2*5 + c1]; 
		}
	}
	return ret;
}

std::string decrypt(std::string key, std::string cipher){
	int i, r1, r2, c1, c2;
	auto matrix = make_matrix(key);
	std::string ret = cipher;
	for (i = 0; i+1<cipher.size(); i+=2){
		r1 = matrix[cipher[i]].first;
		r2 = matrix[cipher[i+1]].first;
		c1 = matrix[cipher[i]].second;
		c2 = matrix[cipher[i+1]].second;
		if (r1==r2){
			c1 = (c1-1)%5;
			c2 = (c2-1)%5;
			ret[i] = key[r1*5 +c1];
			ret[i+1] = key[r2*5 + c2];
		}
		else if (c1==c2){
			r1 = (r1-1)%5;
			r2 = (r2-1)%5;
			ret[i] = key[r1*5 +c1];
			ret[i+1] = key[r2*5 + c2];
		}
		else{
			ret[i] = key[r1*5 + c2];
			ret[i+1] = key[r2*5 + c1]; 
		}
	}
	return ret;
}

int main(){
	std::string plain, cipher, key;
	std::cout << "Key?: ";
	std::cin >> key;
	key = get_key_string(key);
	auto matrix = make_matrix(key);
	std::cout << "Plain text?:";
	std::cin >> plain;
	cipher = encrypt(key, plain);  
	std::cout << cipher << std::endl;
	std::cout << decrypt(key, cipher)<< std::endl;
}
