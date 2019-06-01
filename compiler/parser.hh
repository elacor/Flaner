#ifndef _FLANER_COMPILER_PARSER_HH_
#define _FLANER_COMPILER_PARSER_HH_

#include <token.hh>
#include <scanner.hh>
#include <declaration.hh>

/*
* File: parser.hh
* Note: ���� token �б�����﷨����
*/

namespace Flaner
{
	namespace Compiler
	{
		namespace Parser
		{

			//  ����ʱ�˺���ʱ����ǰ token �Ѿ��� identifier
			std::unique_ptr<AST::Identifier> parseIdentifier(std::unique_ptr<Lex::TokenList> tokenList)
			{
				std::unique_ptr<AST::Identifier> identifier = tokenList->now();
				return identifier;
			}

			// ���ô˺���ʱ����ǰ token �� '(' �� identifier
			std::unique_ptr<AST::Value> parseValue(std::unique_ptr<Lex::TokenList> tokenList)
			{
				AST::Value value;
				Lex::Token now = tokenList->next();
				if (now.is(TOKEN_IDENTIFIER))
				{
					value.form = now;
					return value;
				}
				else if (now.is(TOKEN_PAREN_BEGIN))
				{
					AST::Expression expression;
					tokenList->next();
					expression = parseExpression(tokenList);
					return AST::Value(AST::Expression);
				}
				else if (now.is(TOKEN_NUMBER))
				{
					// ��������ֵ

				}
				else if (now.is(TOKEN_STRING))
				{
					// �ַ�������ֵ

				}
				else
				{
					// ���������Ӧ������
					return nullptr;
				}
			}

			std::unique_ptr<AST::UnaryExpression> parseUnaryExpression(std::unique_ptr<Lex::TokenList> tokenList)
			{
				std::unique_ptr<AST::UnaryExpression> unaryExpression;

				// ��ǰ token һ����һ�� unary operator
				std::unique_ptr<AST::UnaryOperator> unaryOperator = tokenList->now();

				// ��ô��һ�� token ��Ӧ����һ�� value
				AST::Value value = parseValue(tokenList);

				if (value == nullptr)
				{
					syntax_error("Unexpected token")
				}

				unaryExpression->right = value;
				unaryExpression->op = unaryOperator;
				
				return value;
			}

			std::unique_ptr<AST::Expression> parseExpression(std::unique_ptr<Lex::TokenList> tokenList)
			{
				
			}

			// ������ parseExpression ʱ����ǰ token �� '('
			Expression parseExpression()
			{
				Expression expression;
				int parenCursor = 0;
				do
				{

					Token t = tokenList.next();
					if (t.is(TOKEN_PAREN_BEGIN))
					{
						parenCursor += 1;
					}

				} while (parenCursor > 0)

			}


			IfStatement parseIfStatement()
			{
				IfStatement ifStatement;
				int parenCursor = 0;
				if (!tokenList.next().is(TOKEN_PAREN_BEGIN))
				{
					syntax_error("mission a '(' after keyword if");
				}

				Expression expr;


		}
	};
};

#endif // !_FLANER_COMPILER_PARSER_HH_
