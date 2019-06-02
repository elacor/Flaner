#ifndef _FLANER_COMPILER_PARSER_HH_
#define _FLANER_COMPILER_PARSER_HH_

#include <token.hh>
#include <scanner.hh>
#include <declaration.hh>
#include <optional>

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

			using TokenList = std::unique_ptr<Lex::TokenList>;

			//  ����ʱ�˺���ʱ����ǰ token �Ѿ��� identifier
			std::unique_ptr<AST::Identifier> parseIdentifier(TokenList tokenList);

			// ���ô˺���ʱ����ǰ token �� '(' �� identifier
			std::unique_ptr<AST::Value> parseValue(TokenList tokenList);

			std::unique_ptr<AST::UnaryExpression> parseUnaryExpression(TokenList tokenList);

			std::unique_ptr<AST::Expression> parseExpression(TokenList tokenList);


			std::unique_ptr<AST::BlockStatement> parseBlockStatement(TokenList tokenList);

			std::unique_ptr<AST::IfStatement> parseIfStatement(TokenList tokenList);

			std::unique_ptr<AST::CaseClause>   parseCaseClause(TokenList tokenList);
			std::unique_ptr<AST::DefaultClause> parseDefaultClause(TokenList tokenList);
			
			using SwitchClause = std::optional<std::variant<std::unique_ptr<AST::CaseClause>, std::unique_ptr<AST::DefaultClause>>>;
			SwitchClause parseSwitchClause(TokenList tokenList);
			
			using SwitchClauseList = std::vector<SwitchClause>;
			SwitchClauseList parseSwitchClauseList(TokenList);

			std::unique_ptr<AST::SwitchStatement> parseSwitchStatement(TokenList tokenList);			

			std::unique_ptr<AST::WhileStatement> parseWhileStatement(TokenList tokenList);

			std::unique_ptr<AST::ForStatement> parseForStatement(TokenList tokenList);

			std::unique_ptr<AST::ContinueStatement> parseContinueStatement(TokenList tokenList);

			std::unique_ptr<AST::BreakStatement> parseBreakStatement(TokenList tokenList);

		}
	};
};

#endif // !_FLANER_COMPILER_PARSER_HH_
