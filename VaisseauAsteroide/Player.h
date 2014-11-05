#pragma once
class Player{
private:
	char *name;
	static int money;
	
public:
	Player(char *name_):
		name(name_){}

	char * getName();
	void setName(char * newName);
	static int	 getMoney();
	static void setMoney(int newMoney);
	static void reset();
	virtual void draw();
};