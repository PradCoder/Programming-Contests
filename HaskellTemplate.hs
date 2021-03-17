-# LANGUAGE FlexibleInstances, UndecidableInstances, DuplicateRecordFields #-}

module Main where

import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import Data.List.Split
import Data.Set
import Debug.Trace
import System.Environment
import System.IO
import System.IO.Unsafe

readMultipleLinesAsStringArray :: Int -> IO [String]
readMultipleLinesAsStringArray 0 = return []
readMultipleLinesAsStringArray n = do
    line <- getLine
    rest <- readMultipleLinesAsStringArray(n - 1)
    return (line : rest)

main :: IO()
main = do
    stdout <- getEnv "OUTPUT_PATH"
    fptr <- openFile stdout WriteMode

    stringsCount <- readLn :: IO Int

    strings <- readMultipleLinesAsStringArray stringsCount

    queriesCount <- readLn :: IO Int

    queries <- readMultipleLinesAsStringArray queriesCount

    let res = matchingStrings strings queries

    hPutStrLn fptr $ intercalate "\n" $ Data.List.map (\x -> show x) $ res

    hFlush fptr
    hClose fptr
