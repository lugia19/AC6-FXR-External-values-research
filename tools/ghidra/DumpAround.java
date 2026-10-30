// Disassembly around an address, with references, for code Ghidra didn't put in a function.
// Usage (headless): -postScript DumpAround.java <address> <bytes before> <bytes after> <output file>
// @category AC6
import java.io.FileWriter;
import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;

public class DumpAround extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Address center = toAddr(args[0]);
        Address start = center.subtract(Long.parseLong(args[1]));
        Address end = center.add(Long.parseLong(args[2]));
        try (PrintWriter out = new PrintWriter(new FileWriter(args[3]))) {
            out.println("function before: " + getFunctionBefore(center) + ", after: " + getFunctionAfter(center));
            Address at = start;
            while (at.compareTo(end) < 0) {
                Instruction instruction = getInstructionAt(at);
                if (instruction == null) {
                    disassemble(at);
                    instruction = getInstructionAt(at);
                }
                if (instruction == null) {
                    out.println(at + "  ?? " + String.format("%02x", getByte(at)));
                    at = at.add(1);
                    continue;
                }
                StringBuilder refs = new StringBuilder();
                for (Reference ref : instruction.getReferencesFrom()) {
                    refs.append(" -> ").append(ref.getToAddress());
                    String label = getSymbolAt(ref.getToAddress()) == null ? "" : getSymbolAt(ref.getToAddress()).getName();
                    if (!label.isEmpty()) {
                        refs.append(" (").append(label).append(")");
                    }
                }
                out.println(at + (at.equals(center) ? " >" : "  ") + instruction + refs);
                at = instruction.getMaxAddress().add(1);
            }
        }
    }
}
