<a name="readme-top"></a>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


# Amibroker Connector with Extended Functionality

This repository contains a modified version of the Amibroker sample connector code, enhanced to include additional functionality for sending text parameters to a webhook server. The modified code enables users to utilize the `PlaceOrder()` function in Amibroker AFL code to send parameters such as 'IntType | buy_sell | symbol | qty | orderType | productType | limitPrice | triggerPrice | TSL | Strategy_tag' to a webhook server or any other destination.

<!-- GETTING STARTED -->
## Getting Started

1. Clone the repository to your local machine with Visual Studio.
2. Make sure you have C installed with MFC build tools.
3. Goto Project Properties -> C/C++ -> Code Generation. Change **Runtime Library** to **Multi-threaded DLL**.
4. Build your project.
5. Copy your output dll to Amibroker plugins dir.

If everything goes well, you will get a prompt message at the start of Amibroker App.

## Usage

Modify your Amibroker AFL code to include the necessary parameters and call the PlaceOrder("") function.

Ensure that your webhook server or destination is configured to receive and process the parameters sent by the function.

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [AFL Plugin Sample](https://www.amibroker.com/download.html)


<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/MysticCodolic/Amibroker-AFL-Webhook-Connector.svg?style=for-the-badge
[contributors-url]: https://github.com/MysticCodolic/Amibroker-AFL-Webhook-Connector/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/MysticCodolic/Amibroker-AFL-Webhook-Connector.svg?style=for-the-badge
[forks-url]: https://github.com/MysticCodolic/Amibroker-AFL-Webhook-Connector/network/members
[stars-shield]: https://img.shields.io/github/stars/MysticCodolic/Amibroker-AFL-Webhook-Connector.svg?style=for-the-badge
[stars-url]: https://github.com/MysticCodolic/Amibroker-AFL-Webhook-Connector/stargazers
[issues-shield]: https://img.shields.io/github/issues/MysticCodolic/Amibroker-AFL-Webhook-Connector.svg?style=for-the-badge
[issues-url]: https://github.com/MysticCodolic/Amibroker-AFL-Webhook-Connector/issues
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/pronoychowdhury

