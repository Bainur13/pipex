# `Pipex` – Unix Pipe and Process Management

## Description

**pipex** is a project that replicates shell pipeline behavior by executing multiple commands with UNIX pipes.  
It demonstrates the handling of process creation, inter-process communication, and file descriptor manipulation.

## Features

- Executes two or more commands linked by pipes
- Supports infile and outfile redirection
- Handles error cases and invalid commands
- Mandatory part fully completed (bonus not included)

## Skills & Concepts Practiced

✔️ UNIX system calls (`fork`, `execve`, `pipe`, `dup2`, `close`)  
✔️ Process management and synchronization  
✔️ File descriptor manipulation  
✔️ Argument parsing and path resolution  
✔️ Error handling and resource cleanup

## Why this project matters

This project deepened my understanding of how shells and pipelines work at the system call level — essential knowledge for system programming, scripting, and operating system development.

## Project Status

✅ Completed with 93% score (mandatory part only)

## Usage Example

```bash
./pipex infile "ls -l" "wc -l" outfile
