#include "Que.h"

//-----------------------------------------PUSH AND PULL REQUESTS FOR QUE-----------------------------------------------------

// SEND FUNCTIONS 
void que::sendMessage(message msg, int weight) //CATCH MESSAGE, PASS TO MESSAGE QUE.
{
	node* newNode = new node(msg, weight);

	if (root == nullptr)
	{
		root = newNode;

		setRoot(true);
	}

	else
	{
		node* focus = root;
		node* parent;

		while (true) 
		{

			parent = focus;

			if (newNode->weight < focus->weight)
			{
				focus = focus->left;
				std::cout << "focus shifting left \n";
				if (focus == nullptr)
				{
					parent->left = newNode;
					std::cout << "node made left\n";
					return;
				}
			}
			else
			{
				focus = focus->right;
				std::cout << "focus shifting right \n";
				if (focus == nullptr)
				{
					parent->right = newNode;
					std::cout << "node made right\n";
					return;
				}
			}
		}

	}
};

void que::sendMessage(message pass) //OVERLOAD FUNCTION, SEND MESSAGE TO SWITCH STATEMENT, DO SOMETHING.
{
	switch (pass)
	{
	case(START):
		std::cout << " START \n";

		break;
	case(TEST):
		std::cout << " TEST \n";

		break;
	case(ROOT):

		break;


	default:
		break;
	}
}

//FETCH FUNCTIONS
que::message que::fetchPost() //FETCH MESSAGE FROM QUE
{

	node* focus = root;
	node* prevFocus = root;

	while (true)
	{

		if (getRoot() == false)
		{
			std::cout << "ROOT REACHED \n";

			return ROOT;
		}
		else
		{
			if (focus->left == nullptr)
			{

				if (focus->right == nullptr)
				{

					std::cout << "post grabbed\n";
					message msg = focus->msg;

					switch (getFlag())
					{

					case(true):
						prevFocus->right = nullptr;
						break;
					case(false):
						prevFocus->left = nullptr;
						break;
					}
					if (prevFocus == root)
					{
						setRoot(false);
					}
					delete focus;
					std::cout << "focus cleared\n";
					return msg;
				}
				else
				{
					prevFocus = focus;
					focus = focus->right;
					setFlag(true);
					std::cout << "focus shifting right \n";
				}


			}
			else
			{

				prevFocus = focus;
				focus = focus->left;
				setFlag(false);
				std::cout << "focus shifting left \n";
			};
		}




	}

}

//----------------------------------------------------------------------------------------------------------------------------