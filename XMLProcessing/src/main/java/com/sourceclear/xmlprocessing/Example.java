package com.sourceclear.xmlprocessing;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamReader;
import javax.xml.transform.stream.StreamSource;

/**
 *
 */
public class Example {

  public static void main(String[] args) throws Exception {
    if(args.length < 1)
      System.out.println("usage: java -jar XMLProcessing.jar input.xml");
    else {
      JAXBContext jc = JAXBContext.newInstance(Student.class);

      XMLInputFactory xif = XMLInputFactory.newFactory();

      xif.setProperty(XMLInputFactory.IS_SUPPORTING_EXTERNAL_ENTITIES, true);
      XMLStreamReader xsr = xif.createXMLStreamReader(new StreamSource(args[0]));

      Unmarshaller unmarshaller = jc.createUnmarshaller();
      Student stud = (Student) unmarshaller.unmarshal(xsr);

      Marshaller marshaller = jc.createMarshaller();
      marshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
      marshaller.marshal(stud, System.out);
    }
  }

}
