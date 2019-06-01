#ifndef _FLANER_COMPILER_TOKEN_HH_
#define _FLANER_COMPILER_TOKEN_HH_

#include <string>
#include <vector>

namespace Flaner
{
	namespace Compiler
	{
		namespace Lex
		{
			enum TokenType
			{

			};

			struct Token
			{
				TokenType type;
				std::string value;
				inline bool is(TokenType t)
				{
					return type == t;
				}
			};

			class TokenList
			{
				std::vector<Token> tokens;
			public:

				/*
				* ���ﶨ��
				*         ���       ��ǰ      ��ǰ
				* ��һ�� <------------#------------> ���һ��
				*/

				// ��ĩβ����һ�� token
				void push(Token token);

				// �Ƴ����õ����һ�� token
				Token pop();

				// �����α�λ��
				void resetCursor(int n = 0);

				// ��ȡ��һ�� token���α겻��
				Token last();

				// ��ȡ��ǰ token
				Token now();

				// ��ȡһ�� token���α겻��
				Token next();

				// ���α���ǰ�ƶ� n ��λ�ã����õ���ǰ token
				Token forward(int n);
				Token forward();

				// ���α��ǰ�ƶ� n ��λ�ã����õ���ǰ token
				Token backward(int n);
				Token backward();

				// ��ȡ��һ�� token
				Token first();

				// ��ȡ���һ�� token
				Token end();
				
			};
		};
	};
};

#endif // !_FLANER_COMPILER_TOKEN_HH_
