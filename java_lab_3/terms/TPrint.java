/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_3.terms;

import java_lab_3.VM.*;

public class TPrint extends Term {
    public TPrint(int pos) {
        super(pos);
    }
    
    @Override
    public void execute(Machine a) throws VMException {
        System.out.print((char) a.getCurMem() + " ");
    }
}
