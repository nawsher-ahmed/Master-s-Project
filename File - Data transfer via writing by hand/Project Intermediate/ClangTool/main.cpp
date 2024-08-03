
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace clang;

class FindNamedStructVisitor : public RecursiveASTVisitor<FindNamedStructVisitor> {
public:
  explicit FindNamedStructVisitor(ASTContext *Context)
    : Context(Context) {}

  bool VisitRecordDecl(RecordDecl *Declaration) {
    if (Declaration->isStruct() && Declaration->getNameAsString() == "Input") {
      llvm::outs() << "Detected struct: " << Declaration->getNameAsString() << "\n";

      std::ofstream outFile("extracted_data.txt");
      if (!outFile) {
        llvm::errs() << "Error opening output file\n";
        return false;
      }

      for (const auto &field : Declaration->fields()) {
        QualType fieldType = field->getType();
        outFile << field->getNameAsString() << " : " << fieldType.getAsString() << "\n";
      }

      outFile.close();
    }
    return true;
  }

private:
  ASTContext *Context;
};

class FindNamedStructConsumer : public clang::ASTConsumer {
public:
  explicit FindNamedStructConsumer(ASTContext *Context)
    : Visitor(Context) {}

  virtual void HandleTranslationUnit(clang::ASTContext &Context) {
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }
private:
  FindNamedStructVisitor Visitor;
};

class FindNamedStructAction : public clang::ASTFrontendAction {
public:
  virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
    clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
    return std::make_unique<FindNamedStructConsumer>(&Compiler.getASTContext());
  }
};

int main(int argc, char **argv) {
  if (argc > 1) {
    std::ifstream inputFile(argv[1]);
    std::string sourceCode((std::istreambuf_iterator<char>(inputFile)),
                           std::istreambuf_iterator<char>());
    clang::tooling::runToolOnCode(std::make_unique<FindNamedStructAction>(), sourceCode);
  } else {
    llvm::errs() << "Usage: <program> <source file>\n";
  }
  return 0;
}

