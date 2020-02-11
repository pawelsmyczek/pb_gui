#include "invoicegen.h"

//InvoiceGen::InvoiceGen()
//{

//}

void generatePdf(){
    qDebug() << "Generating pdf";
    QString html =
    "<div align=right>"
       "City, 11/11/2015"
    "</div>"
    "<div align=left>"
       "Sender Name<br>"
       "street 34/56A<br>"
       "121-43 city"
    "</div>"
    "<h1 align=center>DOCUMENT TITLE</h1>"
    "<p align=justify>"
       "document content document content document content document content document content document content document content document content document content document content "
       "document content document content document content document content document content document content document content document content document content document content "
    "</p>"
    "<div align=right>sincerly</div>";

    QString __template =
    "<html> <head> <style type=\"text/css\"> <!-- body { font-family: Arial; font-size: 18.3px } .pos { position: absolute; z-index: 0; left: 0px; top: 0px } --> </style> </head> <body> <nobr><nowrap> <div class=\"pos\" id=\"_0:0\" style=\"top:0\"> <img name=\"_1170:827\" src=\"/home/pablito/Qt_Projects/pb_gui/page_001.jpg\" height=\"1170\" width=\"827\" border=\"0\" usemap=\"#Map\"></div> <div class=\"pos\" id=\"_113:78\" style=\"top:78;left:113\"> <span id=\"_16.3\" style=\"font-weight:bold; font-family:Times New Roman; font-size:16.3px; color:#000000\"> FAKTURA</span> </div> <div class=\"pos\" id=\"_105:97\" style=\"top:97;left:105\"> <span id=\"_16.3\" style=\"font-weight:bold; font-family:Times New Roman; font-size:16.3px;\"> PROFORMA</span> </div> <div class=\"pos\" id=\"_534:99\" style=\"top:99;left:534\"> <span id=\"_12.6\" style=\" font-family:Times New Roman; font-size:12.6px; color:#000000\"> miejscowo  , data</span> </div> <div class=\"pos\" id=\"_103:142\" style=\"top:142;left:103\"> <span id=\"_12.6\" style=\"font-weight:bold; font-family:Times New Roman; font-size:12.6px; color:#000000\"> Termin p&#322;atno  ci</span> </div> <div class=\"pos\" id=\"_256:142\" style=\"top:142;left:256\"> <span id=\"_12.6\" style=\"font-weight:bold; font-family:Times New Roman; font-size:12.6px; color:#000000\"> Forma p&#322;atno  ci</span> </div> <div class=\"pos\" id=\"_462:142\" style=\"top:142;left:462\"> <span id=\"_13.4\" style=\"font-weight:bold; font-family:Times New Roman; font-size:13.4px; color:#000000\"> Data dokonania lub zako  czenia dostawy</span> </div> <div class=\"pos\" id=\"_189:207\" style=\"top:207;left:189\"> <span id=\"_13.4\" style=\"font-weight:bold; font-family:Times New Roman; font-size:13.4px; color:#000000\"> SPRZEDAWCA</span> </div> <div class=\"pos\" id=\"_548:207\" style=\"top:207;left:548\"> <span id=\"_13.4\" style=\"font-weight:bold; font-family:Times New Roman; font-size:13.4px; color:#000000\"> NABYWCA</span> </div> <div class=\"pos\" id=\"_100:334\" style=\"top:334;left:100\"> <span id=\"_13.4\" style=\"font-weight:bold; font-family:Times New Roman; font-size:13.4px; color:#000000\"> Bank, nr</span> </div> <div class=\"pos\" id=\"_109:349\" style=\"top:349;left:109\"> <span id=\"_13.4\" style=\"font-weight:bold; font-family:Times New Roman; font-size:13.4px; color:#000000\"> konta</span> </div> <div class=\"pos\" id=\"_100:400\" style=\"top:400;left:100\"> <span id=\"_15.7\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:15.7px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_193:392\" style=\"top:392;left:193\"> <span id=\"_20.4\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:20.4px; color:#000000\"> </span> </div> <div class=\"pos\" id=\"_469:392\" style=\"top:392;left:469\"> <span id=\"_20.4\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:20.4px; color:#000000\"> 	 </span> </div> <div class=\"pos\" id=\"_536:392\" style=\"top:392;left:536\"> <span id=\"_20.4\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:20.4px; color:#000000\"> 	</span> </div> <div class=\"pos\" id=\"_598:392\" style=\"top:392;left:598\"> <span id=\"_21.0\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:21.0px; color:#000000\"> ! 	</span> </div> <div class=\"pos\" id=\"_171:408\" style=\"top:408;left:171\"> <span id=\"_19.2\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:19.2px; color:#000000\"> 	  </span> </div> <div class=\"pos\" id=\"_303:400\" style=\"top:400;left:303\"> <span id=\"_16.9\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:16.9px; color:#000000\"> </span> </div> <div class=\"pos\" id=\"_345:400\" style=\"top:400;left:345\"> <span id=\"_16.4\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:16.4px; color:#000000\">  </span> </div> <div class=\"pos\" id=\"_388:400\" style=\"top:400;left:388\"> <span id=\"_20.8\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:20.8px; color:#000000\"> 		 </span> </div> <div class=\"pos\" id=\"_478:408\" style=\"top:408;left:478\"> <span id=\"_17.4\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:17.4px; color:#000000\"> 		 </span> </div> <div class=\"pos\" id=\"_544:408\" style=\"top:408;left:544\"> <span id=\"_21.4\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:21.4px; color:#000000\">  </span> </div> <div class=\"pos\" id=\"_603:408\" style=\"top:408;left:603\"> <span id=\"_21.4\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:21.4px; color:#000000\">  </span> </div> <div class=\"pos\" id=\"_659:400\" style=\"top:400;left:659\"> <span id=\"_21.8\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:21.8px; color:#000000\"> 	  </span> </div> <div class=\"pos\" id=\"_107:436\" style=\"top:436;left:107\"> <span id=\"_10.9\" style=\" font-family:Times New Roman; font-size:10.9px; color:#000000\"> 1</span> </div> <div class=\"pos\" id=\"_107:462\" style=\"top:462;left:107\"> <span id=\"_10.9\" style=\" font-family:Times New Roman; font-size:10.9px; color:#000000\"> 2</span> </div> <div class=\"pos\" id=\"_107:488\" style=\"top:488;left:107\"> <span id=\"_10.9\" style=\" font-family:Times New Roman; font-size:10.9px; color:#000000\"> 3</span> </div> <div class=\"pos\" id=\"_107:515\" style=\"top:515;left:107\"> <span id=\"_10.9\" style=\" font-family:Times New Roman; font-size:10.9px; color:#000000\"> 4</span> </div> <div class=\"pos\" id=\"_107:541\" style=\"top:541;left:107\"> <span id=\"_10.9\" style=\" font-family:Times New Roman; font-size:10.9px; color:#000000\"> 5</span> </div> <div class=\"pos\" id=\"_107:567\" style=\"top:567;left:107\"> <span id=\"_10.9\" style=\" font-family:Times New Roman; font-size:10.9px; color:#000000\"> 6</span> </div> <div class=\"pos\" id=\"_107:593\" style=\"top:593;left:107\"> <span id=\"_10.9\" style=\" font-family:Times New Roman; font-size:10.9px; color:#000000\"> 7</span> </div> <div class=\"pos\" id=\"_107:620\" style=\"top:620;left:107\"> <span id=\"_10.9\" style=\" font-family:Times New Roman; font-size:10.9px; color:#000000\"> 8</span> </div> <div class=\"pos\" id=\"_107:646\" style=\"top:646;left:107\"> <span id=\"_10.9\" style=\" font-family:Times New Roman; font-size:10.9px; color:#000000\"> 9</span> </div> <div class=\"pos\" id=\"_398:674\" style=\"top:674;left:398\"> <span id=\"_18.0\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:18.0px; color:#000000\"> \"#$</span> </div> <div class=\"pos\" id=\"_457:682\" style=\"top:682;left:457\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_548:671\" style=\"top:671;left:548\"> <span id=\"_21.7\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:21.7px; color:#000000\"> <li type=\"square\">%</span> </div> <div class=\"pos\" id=\"_613:674\" style=\"top:674;left:613\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_697:674\" style=\"top:674;left:697\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_401:708\" style=\"top:708;left:401\"> <span id=\"_17.5\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:17.5px; color:#000000\"> 	&'</span> </div> <div class=\"pos\" id=\"_457:708\" style=\"top:708;left:457\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_556:708\" style=\"top:708;left:556\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_615:708\" style=\"top:708;left:615\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_698:708\" style=\"top:708;left:698\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_541:777\" style=\"top:777;left:541\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_98:841\" style=\"top:841;left:98\"> <span id=\"_15.9\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:15.9px; color:#000000\"> \"'( 	&)*</span> </div> <div class=\"pos\" id=\"_313:841\" style=\"top:841;left:313\"> <span id=\"_14.6\" style=\" font-family:Arial Narrow; font-size:14.6px; color:#000000\"> <li type=\"square\">	 </span> </div> <div class=\"pos\" id=\"_457:841\" style=\"top:841;left:457\"> <span id=\"_14.6\" style=\" font-family:Arial Narrow; font-size:14.6px; color:#000000\"> <li type=\"square\">   	 </span> </div> <div class=\"pos\" id=\"_309:876\" style=\"top:876;left:309\"> <span id=\"_13.6\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_372:876\" style=\"top:876;left:372\"> <span id=\"_13.6\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_391:876\" style=\"top:876;left:391\"> <span id=\"_13.6\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_438:873\" style=\"top:873;left:438\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_598:876\" style=\"top:876;left:598\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_405:900\" style=\"top:900;left:405\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_438:900\" style=\"top:900;left:438\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_598:892\" style=\"top:892;left:598\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_598:908\" style=\"top:908;left:598\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_189:927\" style=\"top:927;left:189\"> <span id=\"_19.9\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:19.9px; color:#000000\"> + '	&	</span> </div> <div class=\"pos\" id=\"_438:935\" style=\"top:935;left:438\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_550:927\" style=\"top:927;left:550\"> <span id=\"_21.4\" style=\"font-weight:bold; font-family:Arial Narrow; font-size:21.4px; color:#000000\"> + '	 (,<span style=\"font-weight:normal\"> </span></span> </div> <div class=\"pos\" id=\"_438:956\" style=\"top:956;left:438\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_598:955\" style=\"top:955;left:598\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_241:979\" style=\"top:979;left:241\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_397:976\" style=\"top:976;left:397\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_600:971\" style=\"top:971;left:600\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_598:987\" style=\"top:987;left:598\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"></span> </div> <div class=\"pos\" id=\"_597:1003\" style=\"top:1003;left:597\"> <span id=\"_13.6\" style=\" font-family:Arial Narrow; font-size:13.6px; color:#000000\"> <li type=\"square\"> </span> </div> </nowrap></nobr> </body> </html>";
    QTextDocument document;
    document.setHtml(__template);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    //printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("/home/pablito/Qt_Projects/pb_gui/test.pdf");

    document.setPageSize(printer.pageRect().size());
    document.print(&printer);
}