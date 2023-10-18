# chain-of-responsibility

## description

责任链模式通过给多个对象处理请求的机会，避免了将请求的发送方与其接收方耦合在一起。模式将接收对象链起来，并沿着链传递请求，直到对象处理它为止。它具有行为目的并处理对象之间的关系。

## usage

1.可以有多个对象处理一个请求，并且应该自动确定处理程序
2.希望在不显式指定接收者的情况下向几个对象之一发出请求
3.可以处理请求的对象集应该动态指定