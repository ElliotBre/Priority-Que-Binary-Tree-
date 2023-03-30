#pragma once
#include <iostream>
class que
{
public:   

//-----------------------------------------MAIN BINARY TREE STRUCTURE---------------------------------------------------------

	enum message //ENUMERATORS SET TO CALL DIFFERENT FUNCTIONS
	{
		START, 
		ROOT,
		TEST,
	};
	 
	struct node {  //NODE STRUCTURE FOR BINARY TREE
		message msg;
		int weight;
		node* left;
		node* right;

		node(message msg, int weight)
		{
			this->msg = msg;
			this->weight = weight;
			this->left = nullptr;
			this->right = nullptr;
		}
	};

	node* root;

	que() { //INITIALIZER TO FORM ROOT OF BINARY TREE
		root = nullptr;
		std::cout << "-----------------------------------\n" << "Initialising Binary Tree \n";
	}

//----------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------PUSH AND PULL REQUESTS FOR QUE-----------------------------------------------------

	void sendMessage(message msg, int weight); //CATCH MESSAGE, PASS TO MESSAGE QUE
	void sendMessage(message pass); //OVERLOAD FUNCTION, SEND MESSAGE TO SWITCH STATEMENT, DO SOMETHING.
	
	message fetchPost(); //FETCH MESSAGE FROM QUE

//----------------------------------------------------------------------------------------------------------------------------
	
private:

//-------------------------------------------GETTER / SETTER FUNCTIONS--------------------------------------------------------

	bool shiftFlag = false; //FALSE = LEFT, TRUE = RIGHT

	bool getFlag()
	{
		return shiftFlag;
	}
	void setFlag(bool set)
	{
		shiftFlag = set;
	}

	bool rootFlag = false; //FALSE FOR EMPTY ROOT, TRUE FOR UNCLEARED ROOT

	bool getRoot()
	{
		return rootFlag;
	}
	void setRoot(bool set)
	{
		rootFlag = set;
	}

//-----------------------------------------------------------------------------------------------------------------------------

};

