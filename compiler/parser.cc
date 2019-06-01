#include <parser.hh>

namespace Flaner
{
	namespace Compiler
	{
		namespace Parser
		{

			

			std::unique_ptr<AST::Identifier> parseIdentifier(std::unique_ptr<Lex::TokenList> tokenList)
			{
				std::unique_ptr<AST::Identifier> identifier = tokenList->now();
				return identifier;
			}

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

			Lex::TokenList std::unique_ptr<AST::Expression> parseExpression(std::unique_ptr<Lex::TokenList> tokenList)
			{
				return Lex::TokenList std::unique_ptr<AST::Expression>();
			}

			std::unique_ptr<AST::IfStatement> parseIfStatement(std::unique_ptr<Lex::TokenList> tokenList)
			{
				if (tokenList->now() != TOKEN_IF)
				{
					return nullptr;
				}

				if (tokenList->forword() != TOKEN_PAREN_BEGIN)
				{
					syntax_error("mission '(' after keyword if");
				}

				std::unique_ptr<AST::Expression> expression = parseExpression(tokenList);
				
				if (!expression)
				{
					syntax_error("unexpected token ')'");
				}

				if 
			}

		};
	};
};
