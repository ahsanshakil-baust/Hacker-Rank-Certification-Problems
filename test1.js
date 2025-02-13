"use strict";

const fs = require("fs");
const https = require("https");

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", function (inputStdin) {
    inputString += inputStdin;
});

process.stdin.on("end", function () {
    inputString = inputString.split("\n");

    main();
});

function readLine() {
    return inputString[currentLine++];
}

async function getCountryName(code, page = 1) {
    let response;

    try {
        response = await new Promise((resolve, reject) => {
            https
                .get(
                    `https://jsonmock.hackerrank.com/api/countries?page=${page}`,
                    (res) => {
                        let data = "";

                        res.on("data", (chunk) => {
                            data += chunk;
                        });

                        res.on("end", () => {
                            resolve(JSON.parse(data));
                        });
                    }
                )
                .on("error", (err) => {
                    reject(err);
                });
        });
    } catch (err) {
        console.log(err);
        return null;
    }

    const filteredData = response.data.filter((el) => el.alpha2Code == code);

    if (filteredData.length > 0) {
        return filteredData[0].name;
    } else if (page < response.total_pages) {
        return await getCountryName(code, page + 1);
    } else {
        return "Country not found";
    }
}
async function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const code = readLine().trim();

    const name = await getCountryName(code);

    ws.write(`${name}\n`);
}
