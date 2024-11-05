//SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract Bank {

    address public accHolder;
    uint balance = 0;

    constructor() {
        accHolder = msg.sender;
    }

    function withdraw()public payable{
        require(balance > 0,"you broke");
        require(msg.sender==accHolder,"John Doe");
        payable(msg.sender).transfer(balance);
        balance=0;
    }

    function deposit() public payable{
        require(msg.value > 0,"Deposit amt grt than 0");
        require(msg.sender==accHolder,"John Doe");
        balance += msg.value;
    }

    function showBalance()public view returns(uint){
        require(msg.sender==accHolder,"John Doe");
        return balance;
    }
}
