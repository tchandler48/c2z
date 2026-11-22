'  test16c.bas
   CLS
   PRINT "Opening Test File"
   OPEN "I", #1, "test.txt"
   INPUT#1, input$, next$, valuea, valueb%, valuec!, valued#
   CLOSE 1
   PRINT input$, next$, valuea, valued#
TheEnd:
   END
