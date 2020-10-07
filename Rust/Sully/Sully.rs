use std::fs::File;
use std::io::prelude::*;
use std::process::Command;
use std::io::{Error, ErrorKind};

macro_rules! CONTENT {
    () => {
        "use std::fs::File;{1}use std::io::prelude::*;{1}use std::process::Command;{1}use std::io::{{Error, ErrorKind}};{1}{1}macro_rules! CONTENT {{{1}    () => {{{1}        {2}{0}{2}{1}    }}{1}}}{1}{1}fn main() -> std::io::Result<()> {{{1}    let mut i: u32 = {3};{1}    if i > 0 {{{1}        if file!() != {2}Sully.rs{2} {{{1}            i = i - 1;{1}        }}{1}        let content_fmt = format!(CONTENT!(), CONTENT!(), 10 as char, 34 as char, i);{1}        let mut file = File::create(format!({2}Sully_{{}}.rs{2}, i))?;{1}        file.write_all(&content_fmt.into_bytes())?;{1}        let command_compile = Command::new({2}rustc{2}){1}        .arg(format!({2}Sully_{{}}.rs{2}, i)).output()?;{1}        if !command_compile.status.success() {{{1}            let custom_error = Error::new(ErrorKind::Other, format!({2}Can not compile file {{}}{2}, format!({2}Sully_{{}}.rs{2}, i)));{1}            return Err(custom_error);{1}        }}{1}        let binary = format!({2}./Sully_{{}}{2}, i);{1}        let command_binary = Command::new(binary).output()?;{1}        if !command_binary.status.success() {{{1}            let custom_error = Error::new(ErrorKind::Other, format!({2}Can not execute binary {{}}{2}, format!({2}Sully_{{}}.rs{2}, i)));{1}            return Err(custom_error);{1}        }}{1}    }}{1}    Ok(()){1}}}"
    }
}

fn main() -> std::io::Result<()> {
    let mut i: i32 = 5;
    if i > 0 {
        if file!() != "Sully.rs" {
            i = i - 1;
        }
        let content_fmt = format!(CONTENT!(), CONTENT!(), 10 as char, 34 as char, i);
        let mut file = File::create(format!("Sully_{}.rs", i))?;
        file.write_all(&content_fmt.into_bytes())?;
        let command_compile = Command::new("rustc")
        .arg(format!("Sully_{}.rs", i)).output()?;
        if !command_compile.status.success() {
            let custom_error = Error::new(ErrorKind::Other, format!("Can not compile file {}", format!("Sully_{}.rs", i)));
            return Err(custom_error);
        }
        let binary = format!("./Sully_{}", i);
        let command_binary = Command::new(binary).output()?;
        if !command_binary.status.success() {
            let custom_error = Error::new(ErrorKind::Other, format!("Can not execute binary {}", format!("Sully_{}.rs", i)));
            return Err(custom_error);
        }
    }
    Ok(())
}