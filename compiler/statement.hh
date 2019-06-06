#ifndef _FLANER_COMPILER_STATEMENT_HH_
#define  _FLANER_COMPILER_STATEMENT_HH_

#include <global.hh>
#include <declaration.hh>
#include <expression.hh>

#include <memory>
#include <vector>
#include <variant>
#include <tuple>
#include <string>

namespace Flaner
{
	namespace Compiler
	{
		namespace AST
		{
			class Identifier;

			class Statement
			{
			public:
				virtual std::string type();
				virtual void walk();
			};

			class StatementSequence
			{
				std::vector<std::unique_ptr<Statement>> sequence;
			public:
				std::unique_ptr<Statement> get();
				bool next();
				void insert(Statement statement);

			};

			class BlockStatement : public Statement
			{
			public:
				std::unique_ptr<StatementSequence> body;
			};


			class IfStatement : public Statement
			{
			public:
				virtual std::string type();
				virtual void walk();

				std::unique_ptr<Expression> condition;
				std::unique_ptr<BlockStatement> body;

			};

			class ElseClause : public Statement
			{
			public:
				std::unique_ptr<BlockStatement> body;
			};

			class WhileStatement : public Statement
			{
			public:
				std::unique_ptr<Expression> condition;
				std::unique_ptr<BlockStatement> body;
			};

			class DoWhileStatement : public Statement
			{
			public:
				std::unique_ptr<Expression> condition;
				std::unique_ptr<BlockStatement> body;
			};

			class ForStatement : public Statement
			{
			public:
				struct CommonHeader
				{
					std::unique_ptr<Expression> initialization;
					std::unique_ptr<Expression> condition;
					std::unique_ptr<Expression> increment;
				};

				// 保留 for...in 和 for...of 语句的循环头定义
				struct InHeader
				{

				};

				struct OfHeader
				{

				};

				using Header = std::variant<CommonHeader, InHeader, OfHeader>;

			public:
				Header header;
				std::unique_ptr<BlockStatement> body;
			};

			class CaseClause : public Statement
			{
			public:
				std::unique_ptr<Expression> object;
				std::unique_ptr<BlockStatement> body;
			};

			class DefaultClause : public Statement
			{
			public:
				std::unique_ptr<BlockStatement> body;
			};

			class SwitchStatement : public Statement
			{
			public:
				std::unique_ptr<Expression> target;
				std::vector<std::unique_ptr<CaseClause>> cases;
				std::unique_ptr<DefaultClause> defaultClause;
			};

			class TryCatchStatement : public Statement
			{
			public:
				struct CatchStatement
				{
					std::unique_ptr<Identifier> bindingId;
					std::unique_ptr<BlockStatement> body;
				};

			public:
				std::unique_ptr<BlockStatement> tryBlockStatement;
				std::vector<std::unique_ptr<CatchStatement>> catchBodies;
				std::unique_ptr<BlockStatement> finallyBlockStatement;
			};

			class LabelStatement : public Statement
			{
			public:
				std::string name;
			};

			class BreakStatement : public Statement
			{
			public:
				std::unique_ptr<LabelStatement> label;
			};

			class ContinueStatement : public Statement
			{
			public:
				std::unique_ptr<LabelStatement> label;
			};

			class VisitorStatement : public Statement
			{
			public:
				enum Kind
				{
					getter, setter
				};

				Kind kind;
				FunctionValue function;
			};
			
			class ClassStatement : public Statement
			{
			public:
				FunctionValue constructor;
				Identifier name;
				std::vector<std::unique_ptr<ObjectMember>> members;
			};

			class ThrowStatement : public Statement
			{
			public:
				Value value;
			};

			class ImportStatement : public Statement
			{
			public:
				std::string name;
				std::string path;
				std::string rename;
			};

			class WithStatement : public Statement
			{
			public:
				std::unique_ptr<Value> object;
				std::unique_ptr<BlockStatement> body;
			};

			class ReturnStatement : public Statement
			{
			public:
				std::unique_ptr<Value> value;
			};

			class YieldStatement : public Statement
			{
			public:
				std::unique_ptr<Value> value;
			};

		};
	};
};

#endif // !_FLANER_COMPILER_STATEMENT_HH_
