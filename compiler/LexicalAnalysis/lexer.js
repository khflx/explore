
//识别语言示例
/**
 * let arg = 1;
 *
 * while (arg) {
 *  #匿名函数以及作用域
 *  let scope = function () {
 *    console.log("scope");
 *  };
 *  scope();
 * }
 *
 * #匿名函数自调用
 * (function (str) {
 *  console.log(str);
 * }) ("fuck you");
 *
 * #对象
 * let obj = {
 *  test: function () {},
 * };
 *
 * #数组
 * let array = [];
 *
 * #函数
 * function test(arg1, arg2) {
 *  #arguments使用
 *  console.log(arguments);
 * }
 * #作用域限定
 * {
 *  let array = [];
 *  test(1, "fuck you");
 * }
 */
/**
 * 词法单元
 * 1. 关键字
 * 2. 运算符
 * 3. 标识符
 * 4. 常量(数字和字符串)
 * 5. 标点符号
 */
var LU = {
  ID: {
    value: null,
    attr: null
  },
  COMPARISON: {

  },
  NUMBER: {
    value: null,
  },
  LITERAL: {
    value: null,
  }
};


module.exports = function lexer(source) {
  this.forward = 0;
  this.lexemeBegin = 0;
  this.line = 0;
  this.source = source;
  this.currToken = {
    type: null, attr: null
  };
};

var prototype = lexer.prototype;

prototype.getNextToken = function () {

};