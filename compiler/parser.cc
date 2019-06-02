#include <parser.hh>
#include <exception.hh>

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
				Lex::Token now = tokenList->forward();

				if (now == TOKEN_IDENTIFIER)
				{
					value.form = now;
					return value;
				}

				else if (now == TOKEN_PAREN_BEGIN)
				{
					AST::Expression expression;
					tokenList->forward();
					expression = parseExpression(tokenList);
					return AST::Value(AST::Expression);
				}

				else if (now == TOKEN_NUMBER)
				{
					// ��������ֵ

				}

				else if (now == TOKEN_STRING)
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

			std::unique_ptr<AST::BlockStatement> parseBlockStatement(std::unique_ptr<Lex::TokenList> tokenList)
			{
				if (tokenList->now())
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
				
				// ����Ϊ��
				if (!expression)
				{
					syntax_error("Unexpected token ')'");
				}

				// ����������ϣ�����������ź�ĵ�һ�� token ����ʼ��������ı����ţ�
				// ˵������������ֵֹĶ���
				if (tokenList->next().is(PUNCTUATION) && !tokenList->next().is(BEGIN_PUNCTUATION))
				{
					syntax_error(std::string("Invalid or unexpected token" + tokenList->next());
				}

				// ���ܻ��׳����󣬷���һ����ȡ����ȷ��ֵ
				std::unique_ptr<AST::BlockStatement> body = parseBlockStatement(tokenList);

				std::unique_ptr<AST::IfStatement> ifStatement;

				ifStatement->condition = expression;
				ifStatement->body = body;

				return ifStatement;
			}

			std::unique_ptr<AST::CaseClause> parseCaseClause(std::unique_ptr<Lex::TokenList> tokenList)
			{
				Lex::Token token = tokenList->now();
				if (token != TOKEN_CASE)
				{
					unexpected_token_syntax_error(token);
				}

				tokenList->forward();

				// ���ʽ������Ϻ󣬵�ǰ token Ӧ���� ':'
				std::unique_ptr<AST::Expression> expression = parseExpression(tokenList);
				
				token = tokenList->now();
				if (token != TOKEN_COLON)
				{
					unexpected_token_syntax_error(token);
				}

				tokenList->forward();
				std::unique_ptr<AST::BlockStatement> block = parseBlockStatement(tokenList);

				std::unique_ptr<AST::CaseClause> caseClause;
				caseClause->object = expression;
				caseClause->body = block;
				return caseClause;
			}

			std::unique_ptr<AST::SwitchStatement> parseSwitchStatement(std::unique_ptr<Lex::TokenList> tokenList)
			{
				if (tokenList->now() != TOKEN_SWITCH)
				{
					return nullptr;
				}

				std::unique_ptr<AST::SwitchStatement> switchStatement;

				Lex::Token now = tokenList->forward();

				// ����ؼ��ֺ���С����
				if (now != TOKEN_PAREN_BEGIN)
				{
					syntax_error("Invalid or unexpected token '" + now.value);
				}

				AST::Expression expression = parseExpression(tokenList);

				// ����ؼ��ֺ��Ǵ�����
				if (now != TOKEN_BRACE_BEGIN)
				{
					syntax_error("Invalid or unexpected token '" + now.value);
				}

				tokenList->forward();

				std::vector<std::unique_ptr<CaseClause>> cases;
				std::unique_ptr<CaseClause> oneCase;

				do
				{
					oneCase = parseCaseClause();
				} while (oneCase != nullptr);

				while (one)
			}

		};
	};
};
