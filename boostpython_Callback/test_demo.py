#!/usr/bin/python2.7
import soldier
from twisted.internet import reactor, task, defer, threads, protocol

def callback_report(killed):
    print "hi captain, %2d enemies were killed" % killed

def main():
    mySoldier = soldier.soldier("James", 7)
    mySoldier.init(callback_report)
    print mySoldier.greet()
    mySoldier.setId(1)
    print "my ID is changed to %d" % mySoldier.getId()
    mySoldier.start()

    reactor.run()

if __name__ == "__main__":
    main()
